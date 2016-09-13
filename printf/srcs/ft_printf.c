/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 10:59:02 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/02 05:03:45 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	char	*value;
	char	*tmp;
	va_list	ap;

	i = 0;
	j = 0;
	value = malloc(sizeof(char) *1000);
	ft_bzero(value, 1000);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				i--;
			else if (format[i] == '%')
			{
				write(1, &format[i], 1);
				j++;
			}
			else
			{
				tmp = malloc(sizeof(char) *1000);
				ft_bzero(tmp, 1000);
				j = check_flags(ap, format, &i, &tmp, &j);
				free(tmp);
			}
		}
		else
		{
			write(1, &format[i], 1);
			j++;
		}
		i++;
	}
	free(value);
	va_end(ap);
	return (j);
}
