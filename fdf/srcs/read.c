/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:46:03 by nlagache          #+#    #+#             */
/*   Updated: 2016/08/04 18:16:21 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list2	*read_file(char *str)
{
	int		fd;
	t_list2	*list;
	t_list2	*tmp;
	char	*line;

	list = NULL;
	if ((fd = open(str, O_RDONLY)) < 0)
		error("open error\n");
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!list)
		{
			list = coordmap(line, list);
			tmp = list;
		}
		else
		{
			tmp->next = coordmap(line, list);
			tmp = tmp->next;
		}
	}
	if (close(fd) == -1)
		error("fail to close\n");
	return (list);
}
