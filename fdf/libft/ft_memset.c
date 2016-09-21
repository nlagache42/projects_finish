/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:09:54 by nlagache          #+#    #+#             */
/*   Updated: 2016/01/20 13:35:54 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	void	*cp;

	i = 0;
	cp = str;
	while (i != len)
	{
		*((unsigned char *)cp + i) = (unsigned char)c;
		i++;
	}
	return (cp);
}
