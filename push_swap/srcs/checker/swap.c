/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:19:22 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 15:51:02 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	swap_s(t_env **tmp2, char c, t_lst *list_par)
{
	int		tmp;
	int		tmp3;

	if (ft_strcmp(list_par->param, "ss") == 0 && ((*tmp2)->first_a == NULL ||
	(*tmp2)->first_a->next == NULL || (*tmp2)->first_b == NULL ||
	(*tmp2)->first_b->next == NULL))
		return ;
	if (c == 'a' && (*tmp2)->first_a && (*tmp2)->first_a->next)
	{
		tmp = (*tmp2)->first_a->value;
		tmp3 = (*tmp2)->first_a->next->value;
		(*tmp2)->first_a->value = tmp3;
		(*tmp2)->first_a->next->value = tmp;
	}
	if (c == 'b' && (*tmp2)->first_b && (*tmp2)->first_b->next)
	{
		tmp = (*tmp2)->first_b->value;
		tmp3 = (*tmp2)->first_b->next->value;
		(*tmp2)->first_b->value = tmp3;
		(*tmp2)->first_b->next->value = tmp;
	}
}
