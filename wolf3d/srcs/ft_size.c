/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 08:33:06 by nlagache          #+#    #+#             */
/*   Updated: 2016/10/11 09:40:30 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_countcara(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == 32 && str[i])
			i++;
		while (str[i] != 32 && str[i])
			i++;
		j++;
	}
	if (str[i - 1] == 32)
		j--;
	return (j);
}