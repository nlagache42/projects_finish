/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:42:32 by nlagache          #+#    #+#             */
/*   Updated: 2016/02/05 14:21:56 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cp;

	cp = (unsigned char *)s;
	if (s == 0)
		return (0);
	while (n > 0 && *cp != (unsigned char)c)
	{
		n--;
		cp++;
	}
	if (n == 0)
		return (0);
	else
		return (cp);
}
