/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:08:10 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/01 12:45:13 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list.h"

void	init_save(t_lem_in *list)
{
	int			i;
	t_lem_in	*tmp;

	tmp = list;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	list->save = malloc(sizeof(char *) * i + 1);
	list->save[0] = NULL;
}

void	reset_save(t_lem_in *list)
{
	int			i;
	t_lem_in	*tmp;

	i = 0;
	tmp = list;
	while (tmp->save[i])
	{
		free(tmp->save[i]);
		i++;
	}
}

void	save_tab(char *str, t_lem_in *list)
{
	int			i;

	i = 0;
	while (list->save[i])
		i++;
	list->save[i] = ft_strdup(str);
	list->save[i + 1] = NULL;
}

void	check_road(t_lem_in *list)
{
	t_lem_in	*start;
	t_lem_in	*end;

	start = list;
	end = list;
	while (ft_strcmp(start->room_name, g_start))
		start = start->next;
	start->open = 0;
	while (ft_strcmp(end->room_name, g_end))
		end = end->next;
	if (short_road(list, start, end))
		send_ants(list, start);
	else
		error("ERROR : No road founded\n");
}
