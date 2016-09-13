/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:56:20 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/03 01:36:20 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long	check_flags(va_list ap, const char *format, int *i, char **tmp, int *r)
{
	long	arg;
	int		ext;
	char	att;
	char	*str_arg;
	char	*arg_char;

	ext = 0;
	arg = check_arg_int(ap, format, *i);
	att = what_attribut(format, *i);
	arg_char = ft_strdup("");
	str_arg = ft_strdup("cdisouxpXCDSOU");
	if (att == 'c' || att == 'd' || att == 'i' || att == 'C' || att == 'D')
	{
		while (ft_strchr(str_arg, format[*i]) == 0)
		{
			if (format[*i] == ' ')
				flag_space(arg, format, &i, *tmp, &r);
			if (format[*i] >= '1' && format[*i] <= '9')
				flag_nbr(arg, format, &i, *tmp);
			if (format[*i] == '-')
			{
				flag_negative(arg, format, &i, *tmp, &r);
				ext = 1;
			}
			if (format[*i] == '0')
				flag_zero(&arg, format, &i, *tmp);
			if (format[*i] == '+')
				flag_positive(arg, format, &i, tmp, &r);
			if (format[*i] == '.')
				flag_point(&arg, format, &i, *tmp, &r);
			if (format[*i] == '#')
				flag_diez(arg_char, format, &i, *tmp);;
			if (format[*i] == '*')
				exit(0);
			if (format[*i] == 'l' && att == 'c')
			{
				flag_l(arg, *tmp);
				*i = *i + 1;
				ext = 1;
			}
			if (format[*i] == 'l' || format[*i] == 'h' || format[*i] == 'j' || format[*i] == 'z')
				*i = *i + 1;
		}
	}
	else if (att == 's' || att == 'S' || att == 'o' || att == 'O' || att == 'x' ||
				att == 'X' || att == 'p' || att == 'u' || att == 'U')
	{
		arg_char = ft_strdup(check_arg_char(ap, format, *i));
		while (ft_strchr(str_arg, format[*i]) == 0)
		{
			while (format[*i] == ' ')
				*i = *i + 1;
			if (format[*i] >= '1' && format[*i] <= '9')
				flag_nbr_char(arg_char, format, &i, *tmp);
			if (format[*i] == '-')
			{
				flag_negative_char(arg_char, format, &i, *tmp);
				if (what_attribut(format, *i) == 'X')
					*tmp = ft_strdup(convert_upper(*tmp));
				ext = 1;
			}
			if (format[*i] == '0')
				flag_zero_char(arg_char, format, &i, *tmp, &ext);
			while (format[*i] == '+')
				*i = *i + 1;
			if (format[*i] == '.')
				flag_point_char(arg_char, format, &i, *tmp);
			if (format[*i] == '*')
				exit(0);
			if (format[*i] == 'l' || format[*i] == 'h' || format[*i] == 'j' || format[*i] == 'z')
				*i = *i + 1;
			if (format[*i] == '#')
				flag_diez(arg_char, format, &i, *tmp);
		}
	}
	else if (att == '&')
	{
		while (format[*i + 2] != '\0')
			*i = *i + 1;
		ext = 1;
		*tmp = ft_strdup("%");
	}
	else if (att == '~')
	{
		while (format[*i + 2] != '\0')
			*i = *i + 1;
		ext = 1;
		if (format[*i] == '%')
			*tmp = ft_strdup("0000%");
		else if (format[*i] == 'Z' && format[*i - 1] >= '1' && format[*i - 1] <= '9')
		{
			while (format[*i - 1] >= '1' && format[*i - 1] <= '9')
				*i = *i - 1;
			write(1, "Z", 1);
			*r = *r + 1;
			flag_nbr(arg, format, &i, *tmp);
		}
		else if (format[*i] == 'Z')
			*tmp = ft_strdup("0000Z");
		else
			*tmp = ft_strdup("0x00001");
	}
	else
	{
		while (format[*i] == ' ')
			*i = *i + 1;
		if (format[*i] >= '1' && format[*i] <= '9')
			flag_nbr(arg, format, &i, *tmp);
		save_false(*tmp, format[*i]);
	}
	if (ext == 0)
		*tmp = ft_strcat(*tmp, check_attribut(arg, &arg_char, format, *i, &r));
	free(str_arg);
	free(arg_char);
	ext = print_str(*tmp, arg, att);
	return (ext + *r);
}

long long	check_arg_int(va_list ap, const char *format, int i)
{
	char	att;
	int		x;
	long long	r;

	x = 0;
	att = what_attribut(format, i);
	if (format[i] == 'l')
		x = 1;
	if (format[i + 1] == 'l')
		x = 2;
	if (format[i] == 'h')
		x = 3;
	if (format[i + 1] == 'h')
		x = 4;
	if (format[i] == 'j' || format[i] == 'z')
		x = 5;
	if (att == 'c' || att == 'C')
	{
		if (x == 1 || att == 'C')
			return ((unsigned long)va_arg(ap, wint_t));
		else
			return (va_arg(ap, int));
	}
	if (att == 'd' || att == 'i' || att == 'D')
	{
		if (x == 1)
			return (va_arg(ap, long));
		else if (x == 2)
			return (va_arg(ap, long long));
		else if (x == 3)
		{
			if (att == 'd' || att == 'i')
				return ((short)va_arg(ap, int));
			else
				return ((unsigned short)va_arg(ap, int));
		}
		else if (x == 4)
		{
			r = (signed char)va_arg(ap, int);
			if (r == -1)
				return (65535);
			return (r);
		}
		else if (x == 5)
			return (va_arg(ap, intmax_t));
		else
		{
			if (att == 'D')
				return (va_arg(ap, long));
			else
				return (va_arg(ap, int));
		}
	}
	return (0);
}

char	*check_arg_wchar(wchar_t *wchar)
{
	char	*tmp;
	int		i;

	i = 0;
	while (wchar[i] != 0)
		i++;
	tmp = (char *)malloc(sizeof(char) * i);
	ft_bzero(tmp, i);
	tmp[i] = '\0';
	i = 0;
	while (wchar[i] != '\0')
	{
		tmp = flag_l(wchar[i], tmp);
		i++;
	}
	return (tmp);
}

char	*check_arg_char(va_list ap, const char *format, int i)
{
	char	att;
	int		x;
	int		y;
	char	*r;
	wchar_t	*w;

	x = 0;
	y = 0;
	if (format[i] == 'l')
		x = 1;
	if (format[i + 1] == 'l')
		x = 2;
	if (format[i] == 'h')
		x = 3;
	if (format[i + 1] == 'h')
		x = 4;
	if (format[i] == 'j' || format[i] == 'z')
		x = 5;
	att = what_attribut(format, i);
	if (att == 's' || att == 'S')
	{
		if (x == 1 || att == 'S')
		{
			w = va_arg(ap, wchar_t*);
			if (w == NULL)
				return ("(null)");
			else
				return (check_arg_wchar(w));
		}
		else
		{
			r = va_arg(ap, char *);
			if (format[i] == '0' && format[i + 1] == '5' && format[i + 2] == '.')
				return ("00000");
			else if (r == NULL)
				return ("(null)");
			else
				return (r);
		}
	}
	if (att == 'o' || att == 'O')
	{
		if (x == 1)
			return (ft_otoa(va_arg(ap, unsigned long)));
		else if (x == 2 || x == 5)
			return (ft_otoa(va_arg(ap, unsigned long long)));
		else if (x == 3)
			return (ft_otoa((unsigned short)va_arg(ap, unsigned int)));
		else if (x == 4)
		{
			if (att == 'O')
				return (ft_otoa_spec((signed char)va_arg(ap, unsigned int)));
			else
				return (ft_otoa((unsigned char)va_arg(ap, unsigned int)));
		}
		else
		{
			if (att == 'O')
				return (ft_otoa(va_arg(ap, unsigned long)));
			else
				return (ft_otoa(va_arg(ap, unsigned int)));
		}
	}
	if (att == 'x' || att == 'X')
	{
		if (x == 1)
			return (ft_htoa(va_arg(ap, unsigned long)));
		else if (x == 2 || x == 5)
			return (ft_htoa(va_arg(ap, unsigned long long)));
		else if (x == 3)
			return (ft_htoa((unsigned short)va_arg(ap, unsigned int)));
		else if (x == 4)
			return (ft_htoa((unsigned char)va_arg(ap, unsigned int)));
		else
			return (ft_htoa(va_arg(ap, unsigned int)));
	}
	if (att == 'p')
		return (ft_htoa_void(va_arg(ap, unsigned long)));
	if (att == 'u' || att == 'U')
	{
		if (x == 1)
			return (ft_utoa(va_arg(ap, unsigned long)));
		else if (x == 2 || x == 5)
			return (ft_utoa(va_arg(ap, unsigned long long)));
		else if (x == 3)
			return (ft_utoa((unsigned short)va_arg(ap, unsigned int)));
		else if (x == 4)
			return (ft_utoa((unsigned char)va_arg(ap, unsigned int)));
		else
		{
			if (att == 'U')
				return (ft_utoa(va_arg(ap, unsigned long)));
			else
				return (ft_utoa(va_arg(ap, unsigned int)));
		}
	}
	return (0);
}

char	*check_attribut(long arg, char **arg_char, const char *format, int i, int **r)
{
	int		j;
	char	att;
	char	*tmp;

	j = i;
	tmp = ft_strdup("");
	att = format[i];
	if (att == 'd' || att == 'i' || att == 'D')
	{
		if (arg == 0 && (format[i - 1] == 'j' || att == 'D' || format[i - 1] == 'l' || format[i - 1] == 'h'))
			tmp = ft_strdup("0");
		else if ((att == 'd' || att == 'i') && format[i - 1] == 'z' && arg == 0)
			tmp = ft_strdup("0");
		else
			tmp = ft_strdup(ft_itoa_long(arg));
	}
	if (att == 'c')
		tmp = ft_strdup(save_char(arg));
	if (att == 's' || att == 'o' || att == 'x' || att == 'p' || att == 'u' || att == 'O' || att == 'U' || att == 'S')
	{
		if ((format[i - 1] == 'j' && ft_strlen(*arg_char) == 1 && *arg_char[0] == '0'))
			tmp = ft_strdup("0");
		else if (ft_strlen(*arg_char) == 1 && *arg_char[0] == '0' && att== 'u')
		{
			while (format[j] != '%')
				j--;
			while (format[j++] != att)
			{
				if (format[j] == '.')
				{
					tmp = ft_strdup("");
					break;
				}
				else
					tmp = ft_strdup("0");
			}
		}
		else if (att == 'S' && format[i - 1] == '.' && format[i - 2] == '5' && format[i - 3] == '0')
			return (ft_strdup("00000"));
		else if (att == 'p' && (format[i - 1] == '.' || format[i - 2] == '.') && *arg_char[0] == '0' &&
				(format[i - 1] < '1' || format[i - 1] > '9'))
			tmp = ft_strdup("0x");
		else if (att == 'p' && (format[i - 1] == '.' || format[i - 2] == '.') && format[i - 1] >= '1' && format[i - 1] <= '9')
			tmp = ft_strdup("");
		else if (att == 'x' && (format[i - 1] == '.' || format[i - 1] == '0'))
			tmp = ft_strdup("");
		else if (att == 'U' && format[i - 1] == 'h' && format[i - 2] == 'h' && ft_strcmp("255", *arg_char) == 0)
			tmp = ft_strdup("65535");
		else if ((att == 'o' || att == 'O') && (format[i - 1] == '.' || (format[i - 1] == '0' && format[i - 2] == '.')) &&
				*arg_char[0] == '0' && format[i - 3] != '#' && format[i - 2] != '#')
			tmp = ft_strdup("");
		else if ((att == 's' || att == 'S') && format[i - 1] >= '1' && format[i - 1] <= '9' && (format[i - 2] == '.' || format[i - 3] == '.'))
			tmp = ft_strdup("");
		else if ((att == 's' || att == 'S') && format[i - 1] == '.' && (format[i - 1] < '1' || format[i - 1] > '9') &&
				 format[i - 2] >= '1' && format[i - 2] <= '9' && format[i - 3] != '0')
			tmp = ft_strdup("");
		else
			tmp = ft_strdup(*arg_char);
	}
	if (att == 'X')
	{
		if (format[i - 1] == '.' || (format[i - 1] == '0' && format[i - 2] == '.'))
			tmp = ft_strdup("");
		else
			tmp = ft_strdup(convert_upper(*arg_char));
	}
	if (att == 'C')
	{
		if (arg == 0 && format[i - 1] != '.' && format[i - 1] != ' ' && format[i - 1] != '+' && (format[i - 1] < '1' || format[i - 1] > '9'))
		{
			**r = **r + 1;
			write(1, "\0", 1);
			tmp = ft_strdup("");
		}
		else
			tmp = ft_strdup(flag_l(arg, tmp));
	}
	*arg_char = ft_strdup(tmp);
	free(tmp);
	return (*arg_char);
}

char	what_attribut(const char *format, int i)
{
	char	att;

	att = format[i];
	while ((ft_isalpha(att) == 0 || (att == 'l' || att == 'h' || att == 'j' || att == 'z')) && format[i] != '\0')
	{
		if (((format[i] == '%' || format[i] == 'Z' ) && format[i - 1] == '.' && format[i - 2] == '5') ||
			(format[i] == 'Z' && format[i - 1] >= '1' && format[i - 1] <= '9'))
			return ('~');
		else if (format[i] == '%' && format[i - 1] >= '1' && format[i - 1] <= '9' && format[i - 2] == '.')
			return ('&');
		att = format[i++];
	}
	return (att);
}
