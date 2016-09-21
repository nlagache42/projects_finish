/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:16:24 by nlagache          #+#    #+#             */
/*   Updated: 2015/12/02 09:44:49 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	char		*cp1;
	const char	*cp2;
	size_t		i;
	size_t		j;

	cp1 = s1;
	cp2 = s2;
	i = n;
	while (i-- != 0 && *cp1 != '\0')
		++cp1;
	j = cp1 - s1;
	i = n - j;
	if (i == 0)
		return (j + ft_strlen(cp2));
	while (*cp2 != '\0')
	{
		if (i != 1)
		{
			*cp1++ = *cp2;
			--i;
		}
		++cp2;
	}
	*cp1 = '\0';
	return (j + (cp2 - s2));
}
