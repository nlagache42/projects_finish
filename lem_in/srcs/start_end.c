/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 09:17:37 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/01 12:46:08 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list.h"

void	start(char *line)
{
	int		i;
	char	*tmp2;

	i = 0;
	tmp2 = malloc(sizeof(char) * ft_strlen(line));
	if (g_start)
		free(g_start);
	g_start = malloc(sizeof(char) * ft_strlen(line) + 1);
	while (line[i])
	{
		g_start[i] = line[i];
		if (line[0] == '#' || line[0] == 'L')
		{
			ft_putendl(line);
			error("ERROR : Room can't begin by # or L\n");
		}
		if (line[i] == ' ')
			g_start[i] = '\0';
		i++;
	}
	free(tmp2);
}

void	end(char *line)
{
	int		i;
	char	*list2;

	i = 0;
	list2 = malloc(sizeof(char) * ft_strlen(line));
	if (g_end)
	{
		free(g_end);
		g_end = NULL;
	}
	g_end = malloc(sizeof(char) * ft_strlen(line) + 1);
	while (line[i])
	{
		g_end[i] = line[i];
		if (line[0] == '#' || line[0] == 'L')
		{
			ft_putendl(line);
			error("ERROR : Room can't begin by # or L\n");
		}
		if (line[i] == ' ')
			g_end[i] = '\0';
		i++;
	}
	free(list2);
}
