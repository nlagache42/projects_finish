/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:10:05 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/01 13:29:26 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list.h"

int		g_nbr_ants = 0;
char	*g_start = NULL;
char	*g_end = NULL;

void	save_room_2(char *line2, t_lem_in *new, int def)
{
	int		i;

	i = 0;
	while (line2[i] != ' ' && line2[i])
		i++;
	new->room_name = malloc(sizeof(char) * i + 1);
	i = 0;
	while (line2[i] != ' ' && line2[i])
	{
		new->room_name[i] = line2[i];
		i++;
	}
	new->room_name[i] = '\0';
	new->room_link = NULL;
	new->open = 1;
	new->tab = 0;
	if (def == 1)
		new->nb_ants = g_nbr_ants;
	else
		new->nb_ants = 0;
	free(line2);
}

void	save_room(t_lem_in **list, char *line, int def)
{
	t_lem_in	*new;
	t_lem_in	*tmp;
	char		*line2;

	ft_putendl(line);
	new = malloc(sizeof(t_lem_in));
	new->next = NULL;
	tmp = NULL;
	line2 = ft_strdup(line);
	save_room_2(line2, new, def);
	if (*list == NULL)
	{
		new->prev = NULL;
		*list = new;
	}
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		tmp->next->prev = tmp;
	}
}

void	init_2(t_lem_in **list, char **line)
{
	ft_putendl(*line);
	get_next_line(0, line);
	end(*line);
	save_room(list, *line, 0);
}

void	init(t_lem_in **list, char **line, int *x)
{
	(*line[0] == ' ' ? error("ERROR : No space allowed\n") : *line[0]);
	if (*x)
	{
		check_nbr(*line);
		g_nbr_ants = ft_atoi(*line);
		*x = 0;
		(g_nbr_ants == 0 ? error("ERROR : Number of ants < 1\n") : g_nbr_ants);
		ft_putnbr(g_nbr_ants);
		write(1, "\n", 1);
	}
	else if (!ft_strcmp(*line, "##start"))
	{
		ft_putendl(*line);
		get_next_line(0, line);
		start(*line);
		save_room(list, *line, 1);
	}
	else if (!ft_strcmp(*line, "##end"))
		init_2(list, line);
	else if (ft_strchr(*line, '#'))
		ft_putendl(*line);
	else if (ft_strchr(*line, '-'))
		check_link(list, *line);
	else
		save_room(list, *line, 0);
}

int		main(int ac, char **av)
{
	char		*line;
	t_lem_in	*list;
	int			x;

	list = malloc(sizeof(t_lem_in));
	list = NULL;
	x = 1;
	av = 0;
	if (ac == 1)
	{
		while (get_next_line(0, &line))
			init(&list, &line, &x);
		check_room();
		if (list->room_link == NULL)
			error("ERROR : No linked room\n");
		check_road(list);
	}
	else
		error("ERROR : Too much arg\n");
	free_all(list);
	return (0);
}
