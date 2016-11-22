/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:11:26 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 16:41:48 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	sort_param_2(t_lst *list_par, t_env **tmp2)
{
	if (ft_strcmp(list_par->param, "sa") == 0)
		swap_s(tmp2, 'a', list_par);
	if (ft_strcmp(list_par->param, "sb") == 0)
		swap_s(tmp2, 'b', list_par);
	if (ft_strcmp(list_par->param, "ss") == 0)
	{
		swap_s(tmp2, 'a', list_par);
		swap_s(tmp2, 'b', list_par);
	}
	if (ft_strcmp(list_par->param, "pa") == 0 && (*tmp2)->first_b)
		push_a(tmp2);
	if (ft_strcmp(list_par->param, "pb") == 0 && (*tmp2)->first_a)
		push_b(tmp2);
}

void	sort_param(t_lst *list_par, t_env **tmp2)
{
	while (list_par)
	{
		sort_param_2(list_par, tmp2);
		if (ft_strcmp(list_par->param, "ra") == 0)
			rotate_a(tmp2, list_par);
		if (ft_strcmp(list_par->param, "rb") == 0)
			rotate_b(tmp2, list_par);
		if (ft_strcmp(list_par->param, "rr") == 0)
		{
			rotate_a(tmp2, list_par);
			rotate_b(tmp2, list_par);
		}
		if (ft_strcmp(list_par->param, "rra") == 0)
			rev_rotate_a(tmp2, list_par);
		if (ft_strcmp(list_par->param, "rrb") == 0)
			rev_rotate_b(tmp2, list_par);
		if (ft_strcmp(list_par->param, "rrr") == 0)
		{
			rev_rotate_a(tmp2, list_par);
			rev_rotate_b(tmp2, list_par);
		}
		list_par = list_par->next;
	}
}

void	check_sort(t_env *tmp2)
{
	t_env	*list;

	list = tmp2->first_a;
	if (tmp2->first_b != NULL)
		exit(write(1, "KO\n", 3));
	while (list->next)
	{
		if (list->next->value < list->value)
			exit(write(1, "KO\n", 3));
		list = list->next;
	}
	write(1, "OK\n", 3);
}
