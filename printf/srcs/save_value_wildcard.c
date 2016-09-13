/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_value_wildcard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:05:13 by nlagache          #+#    #+#             */
/*   Updated: 2016/08/30 06:55:04 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*flag_wildcard(va_list ap, int arg, const char *format, int **i, char *tmp)
{
	int		x;
	int		arg2;
	int		nbr_space;
	char	att;

	x = 0;
	att = what_attribut(format, **i);
	arg2 = check_arg_int(ap, format, **i);
	nbr_space = 0;
	if (format[**i - 1] >= '0' && format[**i - 1] <= '9')
		x = 1;
	while (format[**i] == '*')
		**i = **i + 1;
	if (format[**i] >= '0' && format[**i] <= '9')
	{
		flag_wildcard_nbr_space(arg2, format, &i, &nbr_space);
		flag_wildcard_nbr(arg2, tmp, nbr_space);
	}
	else if (arg < 0)
		flag_wildcard_negative(arg, arg2, tmp);
	else
		flag_wildcard_positive(arg, arg2, tmp, att);
	if (arg2 == 0 && x == 1)
		tmp = "0";
	return (tmp);
}

int		*flag_wildcard_nbr_space(int arg2, const char *format, int ***i,
		int *nbr_space)
{
	*nbr_space = ft_atoi_long(&format[***i]) - ft_nbrlen_long(arg2);
	while (format[***i] >= '1' && format[***i] <= '9')
		***i = ***i + 1;
	return (nbr_space);
}

char	*flag_wildcard_nbr(int arg2, char *tmp, int nbr_space)
{
	int		x;
	char	*str;

	x = 0;
	str = ft_strdup(ft_itoa_long(arg2));
	while (nbr_space-- > 0)
		tmp[x++] = ' ';
	if (arg2 == 0)
		str = ft_strdup("0");
	tmp = ft_strcat(tmp, str);
	free(str);
	return (tmp);
}

char	*flag_wildcard_negative(int arg, int arg2, char *tmp)
{
	int		x;
	int		y;
	int		nbr_space;
	char	*str;

	x = 0;
	y = 0;
	str = ft_strdup(ft_itoa_long(arg2));
	nbr_space = (arg * -1) - ft_nbrlen_long(arg2);
	x = arg * -1;
	while (str[y] != '\0')
	{
		tmp[y] = str[y];
		y++;
	}
	while (x-- > 1 && nbr_space-- > 0)
		tmp[y++] = ' ';
	free(str);
	return (tmp);
}

char	*flag_wildcard_positive(int arg, int arg2, char *tmp, char att)
{
	int		x;
	int		y;
	int		nbr_space;
	char	*tmp2;
	char	*str;

	x = 0;
	y = 0;
	nbr_space = 0;
	if (att == 'c')
		str = ft_strdup("");
	else if (arg2 == 0)
		str = ft_strdup("0");
	else
		str = ft_strdup(ft_itoa_long(arg2));
	tmp2 = ft_strdup(tmp);
	nbr_space = arg - ft_nbrlen_long(arg2);
	while (arg-- > 1 && nbr_space-- > 0)
		tmp[x++] = ' ';
	while (str[y] != '\0')
		tmp[x++] = str[y++];
	tmp = ft_strcat(tmp2, tmp);
	free(str);
	free(tmp2);
	return (tmp);
}
