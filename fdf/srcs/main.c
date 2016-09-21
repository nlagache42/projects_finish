/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:37:14 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/20 11:11:23 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_list2	*list2;
	int		x;
	int		y;
	int		z;
	int		**tab;

	z = 0;
	list2 = NULL;
	if (argc != 2)
		error("Wrong number of arguments\n");
	list2 = read_file(argv[1]);
	if (!list2)
		error("Map error\n");
	y = list_lenght(list2);
	x = list_to_tab(&tab, list2, y, &z);
	if (y == 0)
		y = 1;
	if (y == 1 && x == 1)
		error("Minimum = 2 points\n");
	if (x > 10000 && y > 10000)
		error("Map is WAAAAAY too big\n");
	activate_mlx(tab, x, y, z);
	return (0);
}
