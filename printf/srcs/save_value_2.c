/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_value_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:32:00 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/03 00:53:21 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*flag_point(long *arg, const char *format, int **i, char *tmp, int **r)
{
	int		nbr_zero;
	int		j;

	j = ft_strlen(tmp);
	if (format[**i - 1] >= '1' && format[**i - 1] <= '9' && format[**i - 2] == '0')
	{
		if (format[**i + 1] >= '1' && format[**i + 1] <= '9')
		{
			**r = **r + 1;
			write(1, " ", 1);
		}
		else
			tmp[j - 1] = '\0';
	}
	while (format[**i] == '.')
		**i = **i + 1;
	nbr_zero = ft_atoi_long(&format[**i]) - ft_nbrlen_long(*arg);
	nbr_zero = (nbr_zero < 0) ? 0 : nbr_zero;
	if (j > 0 && nbr_zero <= j)
		j = j - nbr_zero;
	if (nbr_zero >= j)
		j = 0;
	if ((format[**i] == 'C' || format[**i + 1] == 'C') && *arg <= 0)
	{
		**r = **r + 1;
		write(1, "\0", 1);
	}
	while (format[**i] >= '0' && format[**i] <= '9')
		**i = **i + 1;
	if (format[**i] == 'c' || format[**i] == 'C')
		nbr_zero = 0;
	if (*arg < 0 && nbr_zero > 0)
	{
		if (j > 0)
			j = j - 1;
		tmp[j++] = '-';
		nbr_zero++;
		*arg = *arg * -1;
	}
	while (nbr_zero-- > 0)
		tmp[j++] = '0';
	return (tmp);
}

char	*flag_zero(long *arg, const char *format, int **i, char *tmp)
{
	int		nbr_zero;
	int		j;

	j = ft_strlen(tmp);
	nbr_zero = ft_atoi_long(&format[**i]) - ft_nbrlen_long(*arg);
	nbr_zero = (what_attribut(format, **i) == 'c') ? nbr_zero + 1 : nbr_zero;
	if (format[**i - 1] == ' ' && what_attribut(format, **i) != 'c')
		nbr_zero--;
	if (format[**i - 1] == ' ' && what_attribut(format, **i) == 'd')
		nbr_zero++;
	if (format[**i - 1] == '+' && nbr_zero == 1)
		nbr_zero--;
	while (format[**i] >= '0' && format[**i] <= '9')
		**i = **i + 1;
	if (format[**i] == 'c')
		nbr_zero--;
	if (format[**i] == '-')
		tmp[j++] = '0';
	if (*arg < 0)
	{
		tmp[j++] = '-';
		*arg = *arg * -1;
	}
	while (nbr_zero-- > 0)
		tmp[j++] = '0';
	return (tmp);
}

char	*flag_diez(char *arg_char, const char *format, int **i, char *tmp)
{
	int		j;

	j = 0;
	while (format[**i] == '#' || format[**i] == '.')
		**i = **i + 1;
	if ((format[**i] == 'o' || format[**i] == 'O') && tmp[j] != '0' && arg_char[j] != '0')
		tmp[j++] = '0';
	else if ((format[**i] == 'x' || format[**i] == 'X') && arg_char[j] != '0' && format[**i - 1] != '.')
	{
		tmp[j++] = '0';
		if (format[**i] == 'x')
			tmp[j++] = 'x';
		else
			tmp[j++] = 'X';
	}
	return (tmp);
}
