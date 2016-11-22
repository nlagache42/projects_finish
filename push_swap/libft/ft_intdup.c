/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:41:37 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/14 15:30:20 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intdup(const int *i1, int len)
{
	int		*i2;

	if (!(i2 = (int *)ft_memalloc(sizeof(int) * (len + 1))))
		return (NULL);
	while (len)
	{
		i2[len] = i1[len];
		len--;
	}
	return (i2);
}
