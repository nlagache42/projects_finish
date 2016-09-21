/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:13:28 by nlagache          #+#    #+#             */
/*   Updated: 2015/11/27 15:43:58 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*cp1;
	char	*cp2;
	size_t	i;

	cp1 = (char *)dst;
	cp2 = (char *)src;
	i = 0;
	while (i < n)
	{
		if (cp2[i] == (char)c)
		{
			cp1[i] = cp2[i];
			return (&(cp1[i + 1]));
		}
		cp1[i] = cp2[i];
		i++;
	}
	return (0);
}
