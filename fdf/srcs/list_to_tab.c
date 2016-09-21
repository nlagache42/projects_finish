/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:42:08 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/13 11:53:46 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	cond(t_list2 *list, t_env a, int *z)
{
	if (ft_atoi(list->map[a.x]) > 20000)
		ft_putstr("coord Z too high");
	if (ft_atoi(list->map[a.x]) > *z)
		*z = ft_atoi(list->map[a.x]);
}

static void	fill_int_tab(t_env *a, int ***tab)
{
	while (a->x < a->j)
	{
		(*tab)[a->y][a->x] = 1000000;
		(a->x)++;
	}
	(*tab)[a->y][a->x] = 1000000;
	(a->y)++;
}

int			list_to_tab(int ***tab, t_list2 *list, int list_lenght, int *z)
{
	t_env	a;

	a.j = 0;
	*tab = malloc(sizeof(int*) * list_lenght + 1);
	a.y = 0;
	while (a.y < list_lenght)
	{
		a.i = 0;
		while (list->map[a.i])
			(a.i)++;
		if (a.i > a.j)
			a.j = a.i;
		(*tab)[a.y] = malloc(sizeof(int) * (a.j + 1));
		a.x = 0;
		while (a.x < a.i)
		{
			cond(list, a, z);
			(*tab)[a.y][a.x] = ft_atoi(list->map[a.x]);
			(a.x)++;
		}
		fill_int_tab(&a, tab);
		list = list->next;
	}
	return (a.j);
}
