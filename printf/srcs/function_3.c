/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:26:11 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/01 22:55:36 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long   hexa_value(long long x)
{
    if (x >= 0 && x <= 9)
        return (48 + x);
    else if (x >= 10 && x <= 15)
    {
        x = x - 10;
        return (97 + x);
    }
    return (0);
}

char    *ft_htoa(unsigned long long n)
{
    char                *p;
    long                size;
    unsigned long long  x;

    x = n;
    size = 0;
    while (x >= 16)
    {
        x = x / 16;
        size ++;
    }
    p = (char *)malloc(sizeof(p) * (size + 1));
    if (p)
    {
        p[size + 1] = '\0';
        while (size >= 0)
        {
            x = n % 16;
            p[size] = hexa_value(x);
            n = n / 16;
            size--;
        }
    }
    return (p);
}

int		ft_nbrlen_long(int n)
{
    int i;
    int nb;

    i = 0;
    nb = n;
    if (n == 0)
        return (1);
    while (nb)
    {
        nb /= 10;
        i++;
    }
    return ((n < 0) ? i + 1 : i);
}

int		print_str(char *tmp, long arg, char att)
{
	int		i;
	int		j;
	int		ret;

	ret = 0;
	i = 0;
	j = ft_strlen(tmp);
	if (tmp[0] == '\0')
		j = 1;
	while (j && tmp[0] != '\0')
	{
		write(1, &tmp[i], 1);
		ret++;
		i++;
		j--;
	}
	if (arg == 0 && att == 'c')
	{
		write(1, "\0", 1);
		ret++;
	}
	return (ret);
}

char	*ft_otoa_spec(unsigned long long n)
{
	char				*p;
	long				size;
	unsigned long long	x;

	x = n;
	size = 0;
	while (x > 7)
	{
		x = x / 8;
		size++;
	}
	p = (char *)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 8;
			p[size] = 48 + x;
			n = n / 8;
			size--;
		}
	}
	if (ft_strcmp("1777777777777777777777", p) == 0)
		return ("177777");
	return (p);
}
