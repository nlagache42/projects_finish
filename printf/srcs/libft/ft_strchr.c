/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:03:44 by nlagache          #+#    #+#             */
/*   Updated: 2016/01/20 14:41:46 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	char	d;
	char	*ptr;

	d = (char)c;
	ptr = (char *)s1;
	while (*ptr != '\0' && *ptr != d)
	{
		ptr++;
	}
	if (*ptr == d)
		return (ptr);
	return (NULL);
}
