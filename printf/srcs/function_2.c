/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:25:03 by nlagache          #+#    #+#             */
/*   Updated: 2016/08/31 03:03:28 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char    *ft_btoa(unsigned long n)
{
    long    x;
    long    size;
    char    *str;

    x = n;
    size = 0;
    while (x > 1)
    {
        x = x / 2;
        size++;
    }
    str = (char *)malloc(sizeof(str) * (size + 1));
    if (str)
    {
        str[size + 1] = '\0';
        while (size >= 0)
        {
            x = n % 2;
            str[size] = 48 + x;
            n = n / 2;
            size--;
        }
    }
    return (str);
}

long    ft_convert_byte(char *str)
{
    int     i;
    int     j;
    int     value;

    i = 0;
    j = 128;
    value = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '1')
            value = value + j;
        j = j / 2;
        i++;
    }
    return (value);
}

char    *save_val_base(char *mask, char *val_base)
{
    int     i;
    int     j;
    char    *tmp;

    tmp = ft_strdup(mask);
    i = 0;
    j = 0;
    while (val_base[i + 1] != '\0')
        i++;
    while (mask[j + 1] != '\0')
        j++;
    while (j != 0)
    {
        if (mask[j] == 'x' && i >= 0)
        {
            tmp[j] = val_base[i];
            i--;
        }
        else if (i < 0 && mask[j] == 'x')
            tmp[j] = '0';
        else
            tmp[j] = mask[j];
        j--;
    }
    return (tmp);
}

char    *ft_utoa(unsigned long long n)
{
    char                *p;
    long                size;
    unsigned long long  x;

    x = n;
    size = 0;
    while (x >= 10)
    {
        x /= 10;
        size++;
    }
    p = (char *)malloc(sizeof(p) * (size + 1));
    if (p)
    {
        p[size + 1] = '\0';
        while (size >= 0)
        {
            x = n % 10;
            p[size] = 48 + x;
            n = n / 10;
            size--;
        }
    }
    return (p);
}

char    *ft_htoa_void(unsigned long n)
{
    char    *p;
    char    *tmp;

    tmp = ft_strdup("0x");
    p = ft_strcat(tmp, ft_htoa(n));
    free(tmp);
    return (p);
}
