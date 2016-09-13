/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:18:46 by nlagache          #+#    #+#             */
/*   Updated: 2016/01/20 13:39:12 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	char	*cp1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	cp1 = (char *)s1;
	if (!cp1[0] && !s2[0])
		return (cp1);
	while (*cp1)
	{
		if (*cp1 == s2[0] || s2[0] == '\0')
		{
			i = 0;
			while (*(cp1 + i) == s2[i] || s2[0] == '\0')
			{
				if (s2[i + 1] == '\0')
					return (cp1);
				i++;
			}
		}
		cp1++;
	}
	return (NULL);
}
