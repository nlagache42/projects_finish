/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:58:48 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 15:58:25 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

int				rotate_basic_a(t_pushswap *ps)
{
	int		i;
	int		end;

	if (ps->tmpa < 2)
		return (_ERROR_);
	i = -1;
	end = ps->a[ps->tmpa - 1];
	if (ps->a[0] > end && end > ps->a[1])
	{
		rule_ra(ps);
		return (_SUCCESS_);
	}
	else if (ps->a[0] > end)
	{
		rule_rra(ps);
		return (_SUCCESS_);
	}
	return (_ERROR_);
}

static void		rotate_hard_help(t_pushswap *ps, int i, int tmp, int tmp2)
{
	int		factor_good;

	factor_good = 0;
	while (ps->a[tmp - 1] < ps->a[tmp])
	{
		factor_good++;
		tmp--;
	}
	tmp2 = ps->tmpa;
	tmp = (tmp2 - i) + factor_good;
	while (tmp--)
		rule_rra(ps);
	if (get_fault(ps->a, ps->tmpa) == NO_FAULT)
		return ;
	tmp = factor_good + 1;
	if (tmp == 1 && (tmp2 - i) - 1 <= 0)
		return ;
	while (tmp--)
		rule_pb(ps);
	tmp = (tmp2 - i) - 1;
	while (tmp--)
		rule_ra(ps);
	tmp = factor_good + 1;
	while (tmp--)
		rule_pa(ps);
}

int				rotate_hard_a(t_pushswap *ps)
{
	int		i;
	int		factor_good;

	i = ps->tmpa;
	factor_good = 0;
	while (--i >= ps->tmpa / 2)
	{
		if (ps->a[i] < ps->a[0])
		{
			rotate_hard_help(ps, i, i, ps->tmpa);
			return (_SUCCESS_);
		}
	}
	return (_ERROR_);
}
