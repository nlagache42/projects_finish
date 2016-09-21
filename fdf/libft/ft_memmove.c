/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:44:08 by nlagache          #+#    #+#             */
/*   Updated: 2015/12/02 09:36:02 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cp1;
	char	*cp2;
	size_t	i;

	cp1 = (char *)dst;
	cp2 = (char *)src;
	i = len;
	if (dst == src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (i > 0)
		{
			cp1[i - 1] = cp2[i - 1];
			i--;
		}
		return (dst);
	}
	return (dst);
}
