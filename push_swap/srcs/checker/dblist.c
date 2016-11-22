/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:18:29 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 16:31:15 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	add_back(t_env **tmp2, int val)
{
	t_env		*new;

	new = malloc(sizeof(t_env));
	new->value = val;
	new->next = NULL;
	if ((*tmp2)->last_a)
	{
		new->prev = (*tmp2)->last_a;
		(*tmp2)->last_a->next = new;
	}
	else
	{
		new->prev = NULL;
		(*tmp2)->first_a = new;
	}
	(*tmp2)->last_a = new;
}

void	count_param(char **av, t_env **tmp2)
{
	int		i;

	i = 0;
	while (av[1][i] != '\0')
	{
		if (ft_atoi_int(&av[1][i]) > 2147483647)
			exit(write(1, "Error\n", 6));
		add_back(tmp2, ft_atoi(&av[1][i]));
		while ((av[1][i] >= '0' && av[1][i] <= '9') || av[1][i] == '-')
			i++;
		if (av[1][i] == ' ')
			i++;
	}
}

void	put_in_dblist(int ac, char **av, t_env **tmp2)
{
	int		i;

	i = 1;
	(*tmp2) = malloc(sizeof(t_env));
	(*tmp2)->first_a = NULL;
	(*tmp2)->last_a = NULL;
	(*tmp2)->first_b = NULL;
	(*tmp2)->last_b = NULL;
	(*tmp2)->ptr = NULL;
	if (ac == 2)
		count_param(av, tmp2);
	else
	{
		while (i < ac)
		{
			if (ft_atoi_int(av[i]) > 2147483647)
				exit(write(1, "Error\n", 6));
			add_back(tmp2, ft_atoi(av[i]));
			i++;
		}
	}
}
