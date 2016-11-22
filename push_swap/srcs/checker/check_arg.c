/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:47:14 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 12:56:01 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

int		split(char **av)
{
	int		i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][0] == ' ')
			return (0);
		if (av[1][i] == ' ')
			i++;
		if ((av[1][i] == ' ' && av[1][i - 1] == ' ') ||
			ft_isdigit(av[1][i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		check_arg_2(char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int		check_arg(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (ac == 2 && ft_strcmp(av[i], " ") > 0)
	{
		if (split(av) == 0)
			return (0);
	}
	else
	{
		if (check_arg_2(av) == 0)
			return (0);
	}
	if (check_double(ac, av) == 0)
		return (0);
	return (1);
}
