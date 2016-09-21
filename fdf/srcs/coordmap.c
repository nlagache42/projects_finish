/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 16:50:23 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/14 18:15:58 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list2	*coordmap(char *line, t_list2 *list)
{
	list = malloc(sizeof(t_list2));
	if (!list)
		error("Malloc error\n");
	list->map = ft_strsplit(line, ' ');
	list->next = NULL;
	return (list);
}
