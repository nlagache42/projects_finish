/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:13:05 by nlagache          #+#    #+#             */
/*   Updated: 2015/12/01 16:07:05 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*s1;
	unsigned int	i;

	s1 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s1)
	{
		i = -1;
		while (s[++i])
		{
			s1[i] = f(s[i]);
		}
		s1[i] = '\0';
	}
	return (s1);
}
