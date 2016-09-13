/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:29:37 by nlagache          #+#    #+#             */
/*   Updated: 2016/02/05 14:29:55 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	int		i;
	char	*cp;

	i = 0;
	cp = 0;
	i = ft_strlen(s1);
	if (c < 0 || c > 225 || c == '\0')
		return (char *)(s1 + i);
	while (i >= 0 && s1[i] != (char)c)
		i--;
	if (i < 0)
		return (0);
	return (char *)(s1 + i);
}
