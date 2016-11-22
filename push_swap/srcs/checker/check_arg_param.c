/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 13:17:18 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 12:53:56 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	double_ac_bis_2(char **av, int *j, int *k)
{
	if (av[1][*j] == ' ')
		*j = *j + 1;
	*k = *j + 1;
}

int		double_ac_bis(char **av)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (av[1][j])
	{
		double_ac_bis_2(av, &j, &k);
		while (av[1][k] != ' ' && av[1][k] != '\0')
			k++;
		while (av[1][k])
		{
			while (av[1][k] < '0' || av[1][k] > '9')
				k++;
			if (av[1][k - 1] == '-')
				k--;
			if (ft_atoi(&av[1][k]) == ft_atoi(&av[1][j]))
				return (0);
			while ((av[1][k] >= '0' && av[1][k] <= '9') || av[1][k] == '-')
				k++;
		}
		while ((av[1][j] >= '0' && av[1][j] <= '9') || av[1][j] == '-')
			j++;
	}
	return (1);
}

int		check_double(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (ac == 2)
	{
		if (double_ac_bis(av) == 0)
			return (0);
	}
	else
	{
		while (av[i])
		{
			j = i + 1;
			while (av[j])
			{
				if (ft_atoi(av[i]) == ft_atoi(av[j]))
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}

void	check_param(char *param)
{
	int		i;
	char	*valid[11];

	valid[0] = "sa";
	valid[1] = "sb";
	valid[2] = "ss";
	valid[3] = "pa";
	valid[4] = "pb";
	valid[5] = "ra";
	valid[6] = "rb";
	valid[7] = "rr";
	valid[8] = "rra";
	valid[9] = "rrb";
	valid[10] = "rrr";
	i = 0;
	while (i < 11 && ft_strcmp(valid[i], param) != 0)
		i++;
	if (i == 11)
		exit(write(1, "Error\n", 6));
}
