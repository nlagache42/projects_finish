/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_value_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 11:53:47 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/03 00:58:20 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*flag_nbr_char(char *arg_char, const char *format, int **i, char *tmp)
{
	int		nbr_space;
	int		j;
	int		len;
	char	att;
	char	*tmp2;

	j = 0;
	att = what_attribut(format, **i);
	len = ft_atoi_long(&format[**i]);
	tmp2 = ft_strdup(tmp);
	nbr_space = len - ft_strlen(arg_char);
	if (format[**i - 1] == '.' && format[**i - 2] == '#')
	{
		if (format[**i + 1] == 'x')
		{
			tmp[0] = '0';
			tmp[1] = 'x';
		}
		while (nbr_space-- > 0)
			tmp2[j++] = '0';
	}
	while (format[**i] >= '0' && format[**i] <= '9')
		**i = **i + 1;
	if ((att == 's' || att == 'S') && format[**i] == '.')
	{
		while (format[**i] == '.')
			   **i = **i + 1;
		if (format[**i] >= '1' && format[**i] <= '9' && ft_atoi_long(&format[**i]) < (int)ft_strlen(arg_char))
			nbr_space = len - ft_atoi_long(&format[**i]);
		else if (format[**i] < '1' || format[**i] > '9')
			nbr_space = len;
		while (format[**i] != '.')
			**i = **i - 1;
	}
	while (nbr_space-- > 0)
		tmp[j++] = ' ';
	tmp = ft_strcat(tmp, tmp2);
	free(tmp2);
	return (tmp);
}

char	*flag_negative_char(char *arg_char, const char *format, int **i, char *tmp)
{
	int		nbr_space;
	char	*str;
	int		len;
	int		x;
	int		j;

	x = 0;
	len = ft_strlen(arg_char);
	while (format[**i] == '-' || format[**i] == ' ' || format[**i] == '+')
		**i = **i + 1;
	nbr_space = ft_atoi_long(&format[**i]) - len + x;
	j = ft_strlen(tmp);
	while (format[**i] >= '0' && format[**i] <= '9')
		**i = **i + 1;
	str = ft_strdup(arg_char);
	while (str[x] != '\0')
		tmp[j++] = str[x++];
	while (nbr_space-- > 0)
		tmp[j++] = ' ';
	free(str);
	return (tmp);
}

char	*flag_zero_char(char *arg_char, const char *format, int **i, char *tmp, int *ext)
{
	int		nbr_zero;
	int		j;
	int		k;
	char	*str_arg;

	k = 0;
	j = ft_strlen(tmp);
	str_arg = ft_strdup("cdisoupXCDSOU");
	nbr_zero = ft_atoi_long(&format[**i]) - ft_strlen(arg_char);
	while (format[**i] >= '0' && format[**i] <= '9')
		**i = **i + 1;
	if (format[**i] == 'p')
	{
		tmp[j++] = '0';
		tmp[j++] = 'x';
		*ext = 1;
		nbr_zero++;
	}
	while (nbr_zero-- > 0)
		tmp[j++] = '0';
	if (format[**i] == 'x' && ft_strchr(str_arg, format[**i]) == 0 && format[**i - 2] != '.')
	{
		while (arg_char[k] != '\0')
			tmp[j++] = arg_char[k++];
	}
	free(str_arg);
	return (tmp);
}

char	*flag_point_char(char *arg_char, const char *format, int **i, char *tmp)
{
	int		nbr_zero;
	int		j;
	int		k;
	int		l;
	char	att;

	k = 0;
	l = 0;
	att = what_attribut(format, **i);
	j = ft_strlen(tmp);
	while (format[**i] == '.')
		**i = **i + 1;
	nbr_zero = ft_atoi_long(&format[**i]) - ft_strlen(arg_char);
	nbr_zero = (nbr_zero < 0) ? 0 : nbr_zero;
	if (j > 0 && nbr_zero <= j && att != 's')
		j = j - nbr_zero;
	if (nbr_zero >= j && att != 's')
		j = 0;
	if (format[**i - 1] == '.' && (att == 's' || att == 'S'))
	{
		k = ft_strlen(arg_char) - ft_atoi_long(&format[**i]);
		if (k < 0)
		{
			nbr_zero = 0;
			k = 0;
			while (arg_char[k] != '\0')
				tmp[j++] = arg_char[k++];
		}
		else
		{
			k = 0;
			l = ft_atoi_long(&format[**i]);
			while (arg_char[k] != '\0' &&  l-- > 0)
				tmp[j++] = arg_char[k++];
		}
	}
	if (format[**i - 1] == '.' && att == 'p' && format[**i] >= '1' && format[**i] <= '9')
	{
		if (format[**i - 2] >= '1' && format[**i - 2] <= '9')
		{
			if ((int)ft_atoi_long(&format[**i]) >= ((int)ft_strlen(arg_char) - 1))
				nbr_zero = ft_atoi_long(&format[**i]) - (ft_strlen(arg_char) - 2);
			else
				nbr_zero = 0;
			j = ft_strlen(tmp);
		}
		else
		{
			nbr_zero = nbr_zero + 2;
			j = 0;
		}
		if ((int)ft_atoi_long(&format[**i]) >= ((int)ft_strlen(arg_char) - 1))
		{
			k = 2;
			tmp[j++] = '0';
            tmp[j++] = 'x';
			while (nbr_zero-- > 0)
				tmp[j++] = '0';
		}
		while (arg_char[k] != '\0')
		{
			tmp[j] = arg_char[k];
			j++;
			k++;
		}
	}
	while (format[**i] >= '0' && format[**i] <= '9')
		**i = **i + 1;
	while (nbr_zero-- > 0)
		tmp[j++] = '0';
	return (tmp);
}
