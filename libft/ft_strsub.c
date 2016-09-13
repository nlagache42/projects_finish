/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:15:24 by nlagache          #+#    #+#             */
/*   Updated: 2015/12/02 09:48:41 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;

	s1 = malloc(sizeof(char) * (len + 1));
	if (s1)
	{
		while (start--)
		{
			s++;
		}
		ft_strncpy(s1, s, len);
		s1[len] = '\0';
	}
	return (s1);
}
