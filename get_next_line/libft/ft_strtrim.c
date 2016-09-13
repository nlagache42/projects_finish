/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:10:42 by nlagache          #+#    #+#             */
/*   Updated: 2015/12/02 13:50:33 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_empty(int c)
{
	return ((c == ' ' || c == '\t' || c == '\n') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	char	*rem;
	int		j;
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	j = 0;
	rem = ft_strnew(ft_strlen(s));
	while (i < ft_strlen(s))
	{
		if (j == 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		else
			rem[j++] = s[i++];
	}
	while (ft_empty(rem[--j]))
		rem[j] = '\0';
	return (rem);
}
