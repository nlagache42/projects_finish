/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:26:53 by nlagache          #+#    #+#             */
/*   Updated: 2016/03/23 14:16:43 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_long(int value)
{
	int		i;

	i = 0;
	if (value < 0)
		i++;
	while (value)
	{
		i++;
		value /= 10;
	}
	return (i);
}

static	char	*ft_maxi(void)
{
	char	*cp;

	cp = ft_strnew(ft_long(-2147483648) + 1);
	ft_strcpy(cp, "-2147483648");
	return (cp);
}

char			*ft_itoa(int n)
{
	char	*cp;
	int		j;

	if (n == -2147483648)
		return (ft_maxi());
	cp = ft_strnew(ft_long(n) + 1);
	j = ft_long(n) - 1;
	if (cp)
	{
		if (n < 0)
		{
			cp[0] = '-';
			n *= -1;
		}
		if (n == 0)
			*cp = '0';
		while (n > 0)
		{
			cp[j] = '0' + (n % 10);
			n /= 10;
			j--;
		}
	}
	return (cp);
}
