/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:23:59 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 15:49:50 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	push_front_a(t_env **tmp2, int val_arg)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	new->value = val_arg;
	if ((*tmp2)->first_a)
	{
		new->prev = NULL;
		(*tmp2)->first_a->prev = new;
		new->next = (*tmp2)->first_a;
		(*tmp2)->first_a = new;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
		(*tmp2)->first_a = new;
		(*tmp2)->last_a = new;
	}
}

void	push_front_b(t_env **tmp2, int val_arg)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	new->value = val_arg;
	if ((*tmp2)->first_b)
	{
		new->prev = NULL;
		(*tmp2)->first_b->prev = new;
		new->next = (*tmp2)->first_b;
		(*tmp2)->first_b = new;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
		(*tmp2)->first_b = new;
		(*tmp2)->last_b = new;
	}
}

void	push_a(t_env **tmp2)
{
	int		val_arg;

	val_arg = (*tmp2)->first_b->value;
	(*tmp2)->ptr = (*tmp2)->first_b;
	(*tmp2)->first_b = (*tmp2)->first_b->next;
	if ((*tmp2)->first_b == NULL)
		(*tmp2)->last_b = NULL;
	else
		(*tmp2)->first_b->prev = NULL;
	free((*tmp2)->ptr);
	push_front_a(tmp2, val_arg);
}

void	push_b(t_env **tmp2)
{
	int		val_arg;

	val_arg = (*tmp2)->first_a->value;
	(*tmp2)->ptr = (*tmp2)->first_a;
	(*tmp2)->first_a = (*tmp2)->first_a->next;
	if ((*tmp2)->first_a == NULL)
		(*tmp2)->last_a = NULL;
	else
		(*tmp2)->first_a->prev = NULL;
	free((*tmp2)->ptr);
	push_front_b(tmp2, val_arg);
}
