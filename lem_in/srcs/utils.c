/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:27:17 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/01 13:01:43 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list.h"

void	check_nbr(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			error("ERROR : Number of ants not valid\n");
		i++;
	}
}

int		alloc_tab(int *len, t_lem_in *list)
{
	*len = 2;
	while (list->next)
	{
		*len = *len + 1;
		list = list->next;
	}
	return (*len);
}

void	free_all(t_lem_in *list)
{
	int		i;

	while (list)
	{
		i = 0;
		free(list->room_name);
		list->room_name = NULL;
		if (list->room_link)
		{
			while (list->room_link[i])
			{
				free(list->room_link[i]);
				i++;
			}
			list->room_link[i] = NULL;
		}
		list = list->next;
	}
}

void	free_all_2(t_lem_out *list)
{
	t_lem_out	*tmp;
	t_lem_out	*del;

	tmp = list;
	while (tmp)
	{
		del = tmp;
		free(del->room_name);
		del->room_name = NULL;
		tmp = tmp->next;
	}
	free(list);
	list = NULL;
}
