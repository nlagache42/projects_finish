/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:13:21 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 15:56:49 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	get_arg_help(t_pushswap *ps, int ac, char **av, int arg)
{
	char	**list;
	int		i;
	int		j;
	int		tmp;

	ps->a = (int *)ft_memalloc(sizeof(int) * (ps->len));
	ps->b = (int *)ft_memalloc(sizeof(int) * (ps->len));
	i = arg;
	tmp = -1;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
			ps->a[++tmp] = ft_atoi(list[j]);
		ft_memdel2((void ***)&list);
	}
	ps->tmpa = ps->len;
	ps->tmpb = 0;
}

int		get_arg(t_pushswap *ps, int ac, char **av, int arg)
{
	int		i;
	int		j;
	char	**list;

	i = arg;
	ps->len = 0;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
		{
			if (!ft_strisdigit(list[j]))
				return (_ERROR_);
			ps->len++;
		}
		ft_memdel2((void ***)&list);
	}
	get_arg_help(ps, ac, av, arg);
	return (_SUCCESS_);
}
