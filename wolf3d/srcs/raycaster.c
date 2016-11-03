/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 22:38:39 by nlagache          #+#    #+#             */
/*   Updated: 2016/10/11 09:41:55 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

double		dist_hor(t_env *init, double xcam, double ycam, double angle)
{
	double	sa;
	double	ca;
	double	xy2[2];

	sa = sin(angle * (PI / 180));
	ca = cos(angle * (PI / 180));
	xy2[0] = xcam - (1000 * ca);
	xy2[1] = ycam - (1000 * sa);
	return (adn(init, xy2) * cos((init->camangle - angle) * RAD));
}

void		draw_sky(t_env *init, int x, double sizewall)
{
	int	y;

	y = 0;
	while (y <= (init->center) - (sizewall / 2) + init->camy)
	{
		pixel_put_image(init, x, y, 0x0b65c3);
		y++;
	}
}

void		draw_wall(t_env *init, int x, double sizewall)
{
	int	y;

	y = (init->center) - (sizewall / 2) + init->camy;
	while (y <= (init->center) + (sizewall / 2) + init->camy)
	{
		pixel_put_image(init, x, y, init->dist->color);
		y++;
	}
}

void		draw_floor(t_env *init, int x, double sizewall)
{
	int	y;

	y = (init->center) + (sizewall / 2) + init->camy;
	while (y <= init->height)
	{
		pixel_put_image(init, x, y, 0x2a2828);
		y++;
	}
}

void		raycaster(t_env *init)
{
	int		x;
	double	ang;
	double	sizewall;
	double	distval;

	x = 0;
	ang = init->camangle - 30;
	while (x <= init->width)
	{
		distval = dist_hor(init, init->posinitx, init->posinity, ang);
		sizewall = (double)init->height / (distval);
		draw_wall(init, x, sizewall);
		draw_sky(init, x, sizewall);
		draw_floor(init, x, sizewall);
		x++;
		ang += init->scale;
	}
}
