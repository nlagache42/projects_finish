/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:52:38 by nlagache          #+#    #+#             */
/*   Updated: 2017/01/27 11:38:08 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list.h"

void	init_list2_start(t_lem_out *list2, t_lem_in *start)
{
	t_lem_out	*new;

	new = malloc(sizeof(t_lem_out));
	new->nb_ants = start->nb_ants;
	new->room_name = ft_strdup(start->room_name);
	new->next = NULL;
	new->prev = NULL;
	list2->first = new;
	list2->last = new;
}

void	init_list2(char *str, t_lem_out *list2)
{
	t_lem_out	*new;

	new = malloc(sizeof(t_lem_out));
	new->nb_ants = 0;
	new->room_name = ft_strdup(str);
	new->next = NULL;
	if (list2->last)
	{
		new->prev = list2->last;
		list2->last->next = new;
	}
	else
	{
		new->prev = NULL;
		list2->first = new;
	}
	list2->last = new;
}

void	check_if_empty(t_lem_out *list2)
{
	t_lem_out	*tmp;
	int			i;

	if (list2->last->nb_ants)
		i = list2->last->nb_ants + 1;
	else
		i = 1;
	tmp = list2->last->prev;
	while (tmp)
	{
		if (tmp->nb_ants)
		{
			tmp->nb_ants--;
			tmp->next->nb_ants++;
			ft_putstr(C_BLUE"L");
			ft_putnbr(i);
			ft_putstr(C_NONE"-");
			ft_putstr(C_RED);
			ft_putstr(tmp->next->room_name);
			ft_putstr(C_NONE" ");
			i++;
		}
		tmp = tmp->prev;
	}
	ft_putchar('\n');
}

void	send_ants(t_lem_in *list, t_lem_in *start)
{
	t_lem_out	*list2;
	int			i;

	i = 0;
	list2 = malloc(sizeof(t_lem_out));
	list2->first = NULL;
	list2->last = NULL;
	init_list2_start(list2, start);
	ft_putchar('\n');
	while (list->save[i])
	{
		init_list2(list->save[i], list2);
		i++;
	}
	while (list2->last->nb_ants != g_nbr_ants)
		check_if_empty(list2);
}
