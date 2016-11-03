/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:18:54 by nlagache          #+#    #+#             */
/*   Updated: 2015/12/01 16:52:04 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	how_many(char *s, char c)
{
	int		words;

	while (*s && *s == c)
		s++;
	words = (*s) ? 1 : 0;
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			words++;
		s++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	*begin;
	char	**res;

	words = how_many((char *)s, c);
	if (!s || !c)
		return (0);
	res = (char **)malloc(sizeof(char *) * (how_many((char *)s, c) + 1));
	begin = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (begin != s)
			{
				*(res++) = ft_strsub(begin, 0, s - begin);
			}
			begin = (char *)s + 1;
		}
		s++;
	}
	if (begin != s)
		*(res++) = ft_strsub(begin, 0, s - begin);
	*res = 0;
	return (res - words);
}
