/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:21:30 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 16:21:12 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	display(t_pushswap *ps)
{
	int		i;

	i = -1;
	ft_putendl("\033[33;31m[Pile A]\033[0m");
	while (++i < ps->tmpa)
	{
		if (i == 0)
			ft_printf("\033[33;32m[%d]\033[0m", ps->a[i]);
		else
			ft_printf("--\033[33;32m[%d]\033[0m", ps->a[i]);
	}
	i = -1;
	ft_putendl("\n\033[33;31m[Pile B]\033[0m");
	while (++i < ps->tmpb)
	{
		if (i == 0)
			ft_printf("\033[33;33m[%d]\033[0m", ps->b[i]);
		else
			ft_printf("--\033[33;33m[%d]\033[0m", ps->b[i]);
	}
	if (ps->tmpb > 0)
		ft_putchar('\n');
	ft_putchar('\n');
}
