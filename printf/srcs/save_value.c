/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:47:53 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/02 06:12:39 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*flag_space(int arg, const char *format, int **i, char *tmp, int **r)
{
	int		j;

	j = 0;
	**r = **r;
	if (format[**i + 1] == '-')
	{
		**i = **i + 1;
		return (tmp);
	}
	while (format[**i] == ' ')
		**i = **i + 1;
	if (arg >= 0 && what_attribut(format, **i) != 'c' && what_attribut(format, **i) != 'C')
		tmp[j++] = ' ';
	if (arg == 0 && what_attribut(format, **i) == 'C')
	{
		write(1, "\0", 1);
		**r = **r + 1;
	}
	return (tmp);
}

char	*flag_nbr(int arg, const char *format, int **i, char *tmp)
{
	int		nbr_space;
	int		j;
	char	*tmp2;

	tmp2 = ft_strdup(tmp);
	j = 0;
	nbr_space = ft_atoi_long(&format[**i]) - ft_nbrlen_long(arg);
	nbr_space = (what_attribut(format, **i) == 'c' && arg > 0) ? nbr_space + 1 : nbr_space;
	j = (format[**i - 1] == ' ' && arg >= 0) ? j - 1 : j;
	j = (format[**i - 1] == '+' && arg >= 0) ? j - 1 : j;
	while (format[**i] >= '0' && format[**i] <= '9')
		**i = **i + 1;
	if (format[**i] == '*')
		nbr_space = 0;
	while (nbr_space-- > 0)
		tmp[j++] = ' ';
	tmp2[j++] = '\0';
	tmp = ft_strcat(tmp, tmp2);
	free(tmp2);
	return (tmp);
}

char	*flag_negative(int arg, const char *format, int **i, char *tmp, int **r)
{
	int		nbr_space;
	char	*str;
	int		x;
	int		j;

	x = 0;
	x = (format[**i - 1] == '+' && arg >= 0) ? -1 : 0;
	while (format[**i] == '-' || format[**i] == ' ' || format[**i] == '+')
		**i = **i + 1;
	nbr_space = ft_atoi_long(&format[**i]) - ft_nbrlen_long(arg) + x;
	if (format[**i - 1] == '+')
	{
		flag_positive(arg, format, i, &tmp, r);
		nbr_space = (arg >= 0) ? nbr_space - 1 : nbr_space;
	}
	j = ft_strlen(tmp);
	if (format[**i - 1] == ' ' && arg >= 0 && x == 0)
	{
		tmp[j++] = ' ';
		nbr_space--;
	}
	x = 0;
	while (format[**i] >= '0' && format[**i] <= '9')
		**i = **i + 1;
	str = ft_strdup(ft_itoa_long(arg));
	while (str[x] != '\0' && what_attribut(format, **i) != 'c')
		tmp[j++] = str[x++];
	if (what_attribut(format, **i) == 'c')
	{
		tmp[j++] = *save_char(arg);
		nbr_space++;
	}
	while (nbr_space-- > 0)
		tmp[j++] = ' ';
	free(str);
	return (tmp);
}

char	*flag_positive(int arg, const char *format, int **i, char **tmp, int **r)
{
	int		j;

	j = 0;
	while (format[**i] == '+' || format[**i] == ' ')
		**i = **i + 1;
	if (arg >= 0 && what_attribut(format, **i) != 'c' && what_attribut(format, **i) != 'C')
		*tmp[j++] = '+';
	else if (what_attribut(format, **i) == 'C')
	{
		write(1, "\0", 1);
		**r = **r + 1;;
	}
	return (*tmp);
}

char	*save_false(char *tmp, char c)
{
	int		i;

	i = 0;
	while (tmp[i] != '\0')
	{
		i++;
	}
	tmp[i++] = c;
	return (tmp);
}
