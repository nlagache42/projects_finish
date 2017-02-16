/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:57:13 by nlagache          #+#    #+#             */
/*   Updated: 2017/01/27 15:59:00 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list.h"

int		check_block(t_lem_in *list, t_lem_in *end, t_lem_in *tmp2)
{
	t_lem_in	*test;

	test = list;
	end->open = 0;
	while (test)
	{
		if (test->open == 1 || !ft_strcmp((tmp2)->room_link[(tmp2)->tab],
			end->room_name))
			return (1);
		test = test->next;
	}
	return (0);
}

int		short_road_2(t_lem_in **tmp, t_lem_in **tmp2, t_lem_in **end,
			t_lem_in *list)
{
	while (ft_strcmp((*tmp)->room_name, (*tmp2)->room_link[(*tmp2)->tab]))
	{
		if (!ft_strcmp((*tmp2)->room_link[(*tmp2)->tab], (*end)->room_name))
			*tmp = *end;
		else if ((*tmp2)->room_link[(*tmp2)->tab + 1])
			(*tmp2)->tab++;
		else
			*tmp = (*tmp)->next;
	}
	if (check_block(list, *end, *tmp2) == 0)
		return (0);
	else if (!ft_strcmp((*tmp)->room_name, (*tmp2)->room_link[(*tmp2)->tab]))
	{
		save_tab((*tmp)->room_name, list);
		(*tmp)->open = 0;
		*tmp2 = *tmp;
		if (!ft_strcmp((*tmp)->room_name, (*end)->room_name))
			return (1);
	}
	return (1);
}

int		short_road(t_lem_in *list, t_lem_in *start, t_lem_in *end)
{
	t_lem_in	*tmp;
	t_lem_in	*tmp2;

	init_save(list);
	tmp = list;
	tmp2 = start;
	if (!ft_strcmp(tmp->room_name, end->room_name))
		tmp = tmp->next;
	while (ft_strcmp(tmp->room_name, end->room_name))
	{
		tmp = list;
		while (tmp->open == 0 || !ft_strcmp(tmp->room_name, end->room_name))
		{
			if (tmp->next == NULL)
			{
				tmp = end;
				break ;
			}
			tmp = tmp->next;
		}
		if (short_road_2(&tmp, &tmp2, &end, list) == 0)
			return (0);
	}
	return (1);
}
