/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 09:19:01 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/01 12:46:58 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list.h"

void	save_room_link_2(t_lem_in *tmp, t_lem_in *tmp2, int len)
{
	int		i;

	i = 0;
	if (tmp2->room_link == NULL)
	{
		tmp2->room_link = malloc(sizeof(char *) * len);
		tmp2->room_link[1] = NULL;
		tmp2->room_link[0] = ft_strdup(tmp->room_name);
	}
	else
	{
		while (tmp2->room_link[i])
			i++;
		tmp2->room_link[i] = ft_strdup(tmp->room_name);
		tmp2->room_link[i + 1] = NULL;
	}
}

void	save_room_link(t_lem_in *tmp, t_lem_in *tmp2, t_lem_in **list)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	alloc_tab(&len, *list);
	if (tmp->room_link == NULL)
	{
		tmp->room_link = malloc(sizeof(char *) * len);
		tmp->room_link[1] = NULL;
		tmp->room_link[0] = ft_strdup(tmp2->room_name);
	}
	else
	{
		while (tmp->room_link[i])
			i++;
		tmp->room_link[i] = ft_strdup(tmp2->room_name);
		tmp->room_link[i + 1] = NULL;
	}
	save_room_link_2(tmp, tmp2, len);
}

void	check_link_2(t_lem_in **list, t_lem_in *tmp, char *line2, int i)
{
	int			j;
	char		*tmp3;
	t_lem_in	*tmp2;

	j = i;
	tmp2 = *list;
	ft_putendl(line2);
	while (line2[i])
		i++;
	tmp3 = malloc(sizeof(char) * i + 1);
	i = j;
	j = 0;
	while (line2[i])
		tmp3[j++] = line2[i++];
	tmp3[j] = '\0';
	while (!ft_strstr(tmp2->room_name, tmp3))
	{
		tmp2 = tmp2->next;
		if (tmp2 == NULL)
			error("ERROR : Room not assigned\n");
	}
	free(tmp3);
	save_room_link(tmp, tmp2, list);
}

void	check_link_bis(char *tmp3, char *line2, int *i)
{
	*i = 0;
	while (line2[*i] != '-')
	{
		tmp3[*i] = line2[*i];
		*i = *i + 1;
	}
	tmp3[*i] = '\0';
}

void	check_link(t_lem_in **list, char *line)
{
	int			i;
	t_lem_in	*tmp;
	char		*line2;
	char		*tmp3;

	i = 0;
	tmp = *list;
	line2 = malloc(sizeof(char) * ft_strlen(line));
	while (line2[i] != '-')
		i++;
	tmp3 = malloc(sizeof(char) * i + 1);
	check_link_bis(tmp3, line2, &i);
	i++;
	while (!ft_strstr(tmp->room_name, tmp3))
	{
		tmp = tmp->next;
		if (tmp == NULL)
			error("ERROR : Room not assigned\n");
	}
	free(tmp3);
	check_link_2(list, tmp, line2, i);
	free(line2);
}
