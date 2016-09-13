/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:22:52 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/01 23:19:23 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

long    ft_atoi_long(const char *str)
{
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    k = 1;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '-')
    {
        k = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
            j = j * 10 + str[i] - '0';
        else
            break ;
        i++;
    }
    return (k * j);
}

long	ft_long(long value)
{
	long	i;

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

char	*ft_maxi(void)
{
    char    *cp;

    cp = ft_strnew(ft_long(-2147483648) + 1);
    ft_strcpy(cp, "-2147483648");
    return (cp);
}

char    *ft_itoa_long(long n)
{
    char    *cp;
    int     j;

	if (n == 0)
		return (ft_strdup(""));
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n == USHRT_MAX)
		return (ft_strdup("65535"));
    cp = ft_strnew(ft_long(n) + 1);
    j = ft_long(n) - 1;
    if (cp)
    {
        if (n < 0)
        {
            cp[0] = '-';
            n = -1 * n;
        }
        if (n == 0)
            *cp = '0';
        while (n > 0)
        {
            cp[j] = '0' + (n % 10);
            n = n / 10;
            j--;
        }
    }
    return (cp);
}

char    *ft_otoa(unsigned long long n)
{
    char                *p;
    long                size;
    unsigned long long  x;

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
    return (p);
}
