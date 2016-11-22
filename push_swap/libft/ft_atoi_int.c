/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:18:43 by nlagache          #+#    #+#             */
/*   Updated: 2016/10/05 14:27:55 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

long	ft_atoi_int(const char *str)
{
	int		i;
	long	j;
	int		k;

	i = 0;
	j = 0;
	k = 1;
	if (str[i] == '-')
	{
		k = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			j = j * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	if (j > 2147483647)
		return (2147483648);
	return (k * j);
}
