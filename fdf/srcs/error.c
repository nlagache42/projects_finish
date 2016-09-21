/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:57:17 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/20 11:11:43 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	charerror1(char c)
{
	write(2, &c, 1);
}

void	strerror1(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		charerror1(str[i]);
		i++;
	}
}

void	error(char *str)
{
	strerror1(str);
	exit(0);
}
