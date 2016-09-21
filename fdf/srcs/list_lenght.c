/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lenght.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 17:31:50 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/15 15:47:05 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		list_lenght(t_list2 *begin_list)
{
	int		i;
	t_list2	*bloc;

	i = 1;
	bloc = begin_list;
	while (bloc->next != NULL)
	{
		bloc = bloc->next;
		i++;
	}
	return (i);
}
