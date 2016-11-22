/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:05:27 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 15:59:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	rule_ss(t_pushswap *ps)
{
	rule_sa(ps);
	rule_sb(ps);
}

void	rule_rr(t_pushswap *ps)
{
	rule_ra(ps);
	rule_rb(ps);
}

void	rule_rrr(t_pushswap *ps)
{
	rule_rra(ps);
	rule_rrb(ps);
}
