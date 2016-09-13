/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:39:38 by nlagache          #+#    #+#             */
/*   Updated: 2015/11/25 17:11:53 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*cp1;
	char	*cp2;

	cp2 = (char *)dst;
	cp1 = (char *)src;
	i = 0;
	while (i < n)
	{
		cp2[i] = cp1[i];
		i++;
		if (i == n)
			return (cp2);
	}
	return (cp2);
}
