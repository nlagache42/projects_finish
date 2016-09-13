/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:13:59 by nlagache          #+#    #+#             */
/*   Updated: 2015/12/01 16:06:55 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	unsigned int	i;

	s1 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s1)
	{
		i = -1;
		while (s[++i])
		{
			s1[i] = f(i, s[i]);
		}
		s1[i] = '\0';
	}
	return (s1);
}
