/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:28:04 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 16:25:24 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

static int		check_duplicate(t_pushswap *ps)
{
	int		i;
	int		j;

	i = -1;
	while (++i < ps->len)
	{
		j = -1;
		while (++j < ps->len)
		{
			if (j != i)
			{
				if (ps->a[i] == ps->a[j])
					return (_ERROR_);
			}
		}
	}
	return (_SUCCESS_);
}

static int		check_basic_sort(t_pushswap *ps)
{
	int		i;

	i = ps->len - 1;
	while (--i >= 0)
	{
		if (ps->a[i] > ps->a[i + 1])
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

static int		get_mode(t_pushswap *ps, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-v"))
			ps->print_display = true;
		else if (!ft_strcmp(av[i], "-e"))
			ps->final_display = true;
		else if (!ft_strcmp(av[i], "-c"))
			ps->count_rules = true;
		else if (!ft_strcmp(av[i], "-h"))
			ps->print_rules = false;
		else if (!ft_strcmp(av[i], "?") || !ft_strcmp(av[i], "--help")
			|| !ft_strcmp(av[i], "-help"))
			return (-1);
		else
			return (i - 1);
		i++;
	}
	return (0);
}

void			check_help(t_pushswap *ps, int argc, char **argv)
{
	if ((ps->arg = get_mode(ps, argc, argv)) == -1)
	{
		ft_putstr("help:\n-v : print piles\n-e : print first and final pile\n\
-c : print total\n-h : hide rules\n");
		exit(0);
	}
}

int				main(int argc, char **argv)
{
	t_pushswap		ps;

	ps.count = 0;
	ps.count_rules = false;
	ps.print_rules = true;
	ps.final_display = false;
	ps.print_display = false;
	check_help(&ps, argc, argv);
	if (!get_arg(&ps, argc, argv, ps.arg))
		write(1, "Error\n", 6);
	else if (!check_duplicate(&ps))
		write(1, "Error\n", 6);
	else if (!check_basic_sort(&ps))
	{
		push_swap(&ps);
		if (ps.final_display == true)
			display(&ps);
		if (ps.count_rules == true)
			ft_printf("\033[33m[total = %d]\033[0m\n", ps.count);
	}
	if (ps.a)
		ft_memdel((void **)&ps.a);
	if (ps.b)
		ft_memdel((void **)&ps.b);
	return (0);
}
