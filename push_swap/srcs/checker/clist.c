/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:43:51 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 14:48:40 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

t_lst	*add_back_clist(t_lst *param_clist, char *line)
{
	t_lst	*clist;
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	if (tmp)
	{
		tmp->param = line;
		tmp->next = NULL;
	}
	check_param(tmp->param);
	clist = param_clist;
	while (param_clist && param_clist->next != NULL)
		param_clist = param_clist->next;
	if (param_clist)
		param_clist->next = tmp;
	else
		return (tmp);
	return (clist);
}
