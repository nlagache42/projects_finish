/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:36:00 by nlagache          #+#    #+#             */
/*   Updated: 2015/12/02 12:42:13 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*cp1;
	char	*cp2;

	cp1 = (char *)s1;
	cp2 = (char *)s2;
	if (s1 == 0 || s2 == 0 || n == 0)
		return (0);
	if (s2[0] == '\0')
		return (char *)s1;
	i = 0;
	while (cp1[i] != '\0' && i < n)
	{
		j = 0;
		while (cp1[i + j] == cp2[j] && cp2[j] != '\0' && (i + j) < n)
		{
			j++;
		}
		if (cp2[j] == '\0')
			return (char *)(&(cp1[i]));
		i++;
	}
	return (0);
}
