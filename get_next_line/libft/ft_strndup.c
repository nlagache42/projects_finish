/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:51:52 by nlagache          #+#    #+#             */
/*   Updated: 2016/01/20 13:40:35 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t length)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (length > ft_strlen(s))
		length = ft_strlen(s);
	cpy = (char *)malloc((length + 1) * sizeof(char));
	while (i != length)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
