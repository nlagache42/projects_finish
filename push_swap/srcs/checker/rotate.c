/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 09:05:43 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 15:50:26 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	rotate_a(t_env **tmp2, t_lst *list_par)
{
	int		val;

	if (ft_strcmp(list_par->param, "rr") == 0 && ((*tmp2)->first_a == NULL ||
		(*tmp2)->first_a->next == NULL || (*tmp2)->first_b == NULL ||
		(*tmp2)->first_b->next == NULL))
		return ;
	if ((*tmp2)->first_a == NULL || (*tmp2)->first_a->next == NULL)
		return ;
	val = (*tmp2)->first_a->value;
	(*tmp2)->last_a = (*tmp2)->first_a;
	while ((*tmp2)->last_a->next)
	{
		(*tmp2)->last_a->value = (*tmp2)->last_a->next->value;
		(*tmp2)->last_a = (*tmp2)->last_a->next;
	}
	(*tmp2)->last_a->value = val;
	(*tmp2)->last_a->next = NULL;
}

void	rotate_b(t_env **tmp2, t_lst *list_par)
{
	int		val;

	if (ft_strcmp(list_par->param, "rr") == 0 && ((*tmp2)->first_a == NULL ||
		(*tmp2)->first_a->next == NULL || (*tmp2)->first_b == NULL ||
		(*tmp2)->first_b->next == NULL))
		return ;
	if ((*tmp2)->first_b == NULL || (*tmp2)->first_b->next == NULL)
		return ;
	val = (*tmp2)->first_b->value;
	(*tmp2)->last_b = (*tmp2)->first_b;
	while ((*tmp2)->last_b->next)
	{
		(*tmp2)->last_b->value = (*tmp2)->last_b->next->value;
		(*tmp2)->last_b = (*tmp2)->last_b->next;
	}
	(*tmp2)->last_b->value = val;
	(*tmp2)->last_b->next = NULL;
}

void	rev_rotate_a(t_env **tmp2, t_lst *list_par)
{
	t_env	*new;
	int		val_a;

	if (ft_strcmp(list_par->param, "rrr") == 0 && ((*tmp2)->first_a == NULL ||
		(*tmp2)->first_a->next == NULL || (*tmp2)->first_b == NULL ||
		(*tmp2)->first_b->next == NULL))
		return ;
	if ((*tmp2)->first_a == NULL || (*tmp2)->first_a->next == NULL)
		return ;
	new = malloc(sizeof(t_env));
	val_a = (*tmp2)->last_a->value;
	(*tmp2)->last_a = (*tmp2)->last_a->prev;
	free((*tmp2)->last_a->next);
	(*tmp2)->last_a->next = NULL;
	new->value = val_a;
	new->prev = NULL;
	new->next = (*tmp2)->first_a;
	(*tmp2)->first_a = new;
}

void	rev_rotate_b(t_env **tmp2, t_lst *list_par)
{
	int		val;
	int		val_b;

	if (ft_strcmp(list_par->param, "rrr") == 0 && ((*tmp2)->first_a == NULL ||
		(*tmp2)->first_a->next == NULL || (*tmp2)->first_b == NULL ||
		(*tmp2)->first_b->next == NULL))
		return ;
	if ((*tmp2)->first_b == NULL || (*tmp2)->first_b->next == NULL)
		return ;
	val = (*tmp2)->last_b->value;
	val_b = (*tmp2)->last_b->value;
	while ((*tmp2)->last_b->prev)
	{
		(*tmp2)->last_b->value = (*tmp2)->last_b->prev->value;
		(*tmp2)->last_b = (*tmp2)->last_b->prev;
	}
	(*tmp2)->first_b->value = val_b;
	while ((*tmp2)->last_b->next)
		(*tmp2)->last_b = (*tmp2)->last_b->next;
}
