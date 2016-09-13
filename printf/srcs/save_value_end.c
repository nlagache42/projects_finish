/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_value_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:53:52 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/01 23:55:12 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*save_char(int arg)
{
	char	*c;

	c = malloc(sizeof(char) * 2);
	c[0] = (char)arg;
	c[1] = '\0';
	return (c);
}

char	*convert_upper(char *arg_char)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc((ft_strlen(arg_char) + 1) * sizeof(char));
	while (arg_char[i] != '\0')
	{
		if (arg_char[i] >= 'a' && arg_char[i] <= 'z')
			tmp[i] = arg_char[i] - 32;
		else
			tmp[i] = arg_char[i];
		i++;
	}
	tmp[i] = '\0';
	arg_char = tmp;
	free(tmp);
	return (arg_char);
}

char	*flag_l(long arg, char *tmp)
{
	char	*val_base;
	char	*mask;
	long	x;
	char	*tmp2;

	tmp2 = ft_strdup("");
	val_base = ft_strdup(ft_btoa(arg));
	x = ft_strlen(val_base);
	mask = ft_strdup("");;
	if (x <= 7)
		mask = ft_strdup("0xxxxxxx");
	else if (x <= 11)
		mask = ft_strdup("110xxxxx 10xxxxxx");
	else if (x > 11 && x <= 16)
		mask = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
	else if (x > 16)
		mask = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	tmp2 = save_val_base(mask, val_base);
	ft_strdup(save_value_int(tmp2, &tmp, x));
	free(tmp2);
	free(val_base);
	free(mask);
	return (tmp);
}

char	*save_value_int(char *tmp2, char **tmp, int x)
{
	int		i;
	int		j;
	int		val_byte;
	char	*str;
	char	*str2;

	i = 0;
	j = 0;
	x = 0;
	str2 = ft_strdup("");
	str = (char *)malloc(sizeof(char) * 8);
	val_byte = 0;
	while (tmp2[i] != '\0')
	{
		if (tmp2[i] != ' ')
			str[j] = tmp2[i];
		if (tmp2[i] == ' ' || tmp2[i + 1] == '\0')
		{
			val_byte = ft_convert_byte(str);
			str2[x] = val_byte;
			x++;
			j = 0;
			i++;
		}
		i++;
		j++;
	}
	str2[x++] = '\0';
	*tmp = ft_strdup(ft_strcat(*tmp, str2));
	free(str);
	free(str2);
	return (*tmp);
}
