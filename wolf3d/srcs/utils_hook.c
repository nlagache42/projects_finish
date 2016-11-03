/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 23:41:33 by nlagache          #+#    #+#             */
/*   Updated: 2016/10/13 09:59:04 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
#include <math.h>

void	move(int keycode, t_env *init)
{
	double	sa;
	double	ca;

	if (keycode == 49 && init->run == 20)
		init->run = 10;
	else if (keycode == 49 && init->run == 10)
		init->run = 20;
	if (keycode == 51 && init->activey == 0)
		init->activey = 1;
	else if (keycode == 51 && init->activey == 1 && (init->camy = 0) == 0)
		init->activey = 0;
	if (keycode == 256 && init->mapkey == 0)
		init->mapkey = 1;
	else if (keycode == 256 && init->mapkey == 1)
		init->mapkey = 0;
	sa = sin(init->camangle * RAD) / init->run;
	ca = cos(init->camangle * RAD) / init->run;
	utils(init, keycode, sa, ca);
}

void	free_struct(t_env *init)
{
	int	x;
	int	y;

	y = init->point[0][0]->sizeline - 1;
	while (y >= 0)
	{
		x = init->point[y][0]->sizecol - 1;
		while (x >= 0)
		{
			free(init->point[y][x]);
			x--;
		}
		free(init->point[y]);
		y--;
	}
}

void	load_map(t_env *init)
{
	if (init->point[(int)(init->posinity)][(int)(init->posinitx)]->z == 9)
	{
		free_struct(init);
		free(init->point);
		init->point = NULL;
		init->point = ft_createstruct(init, selectmaps());
		if (init->posinitx == -1 || init->posinity == -1)
			error("error : posinitx == -1");
		init->posinity += 0.5;
		init->posinitx += 0.5;
	}
}
