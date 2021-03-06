/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:50:16 by nlagache          #+#    #+#             */
/*   Updated: 2016/10/05 14:28:13 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

int		ft_atoi(const char *str)
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
	if (j > 2147483648)
		j = j - 2147483648 + 2147483648;
	return (k * j);
}
