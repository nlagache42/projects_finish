/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_begin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:22:15 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 15:57:53 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

static int		swap_last(t_pushswap *ps)
{
	int		min;

	min = get_min(ps->a, ps->tmpa - 2);
	if (ps->a[ps->tmpa - 1] < min && ps->a[ps->tmpa - 2] < min)
	{
		rule_rra(ps);
		rule_rra(ps);
		rule_sa(ps);
		return (_SUCCESS_);
	}
	return (_ERROR_);
}

static int		choice_algo(t_pushswap *ps)
{
	int		cpt;

	cpt = 0;
	while (cpt < ps->tmpa - 1 && ps->a[cpt] < ps->a[cpt + 1])
		cpt++;
	if (cpt == ps->tmpa - 1)
		return (_ERROR_);
	cpt++;
	while (cpt < ps->tmpa - 1 && ps->a[cpt] < ps->a[cpt + 1] &&
			ps->a[cpt + 1] < ps->a[0])
		cpt++;
	if (cpt == ps->tmpa - 1)
		return (EASY_ROTATE);
	cpt++;
	while (cpt < ps->tmpa - 1 && ps->a[cpt] < ps->a[cpt + 1])
		cpt++;
	if (cpt == ps->tmpa - 1 && ps->a[cpt - 1] < ps->a[cpt])
		return (HARD_ROTATE);
	if (get_fault(ps->a, ps->tmpa) + 1 == ps->tmpa - 1)
		return (swap_last(ps));
	return (_ERROR_);
}

int				easy_begin(t_pushswap *ps)
{
	int		choice;

	if (algo_reverse(ps) == _SUCCESS_ && get_fault(ps->a, ps->tmpa) == NO_FAULT)
		return (_SUCCESS_);
	choice = choice_algo(ps);
	if (choice == EASY_ROTATE)
	{
		while (rotate_basic_a(ps) == _SUCCESS_)
			;
		if (get_fault(ps->a, ps->tmpa) == NO_FAULT)
			return (_SUCCESS_);
	}
	else if (choice == HARD_ROTATE)
	{
		while (rotate_hard_a(ps) == _SUCCESS_)
			;
		if (get_fault(ps->a, ps->tmpa) == NO_FAULT)
			return (_SUCCESS_);
	}
	return (_ERROR_);
}
