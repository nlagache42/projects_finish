/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:19:48 by nlagache          #+#    #+#             */
/*   Updated: 2016/10/11 09:45:00 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

static	void	color_code(t_env *init, double x, double y)
{
	if ((int)x > 0 && init->point[(int)y][(int)x - 1]->z != 1 &&
	x - (int)x < 0.0045)
		init->dist->color = 0xff0000;
	else if ((int)x < init->point[(int)y][0]->sizecol - 1 &&
	init->point[(int)y][(int)x + 1]->z != 1 && x - (int)x > 0.9965)
		init->dist->color = 0x00ff00;
	else if ((int)y > 0 && init->point[(int)y - 1][(int)x]->z != 1 &&
	y - (int)y < 0.0045)
		init->dist->color = 0xffed00;
	else if ((int)y < init->point[0][0]->sizeline - 1 &&
	init->point[(int)y + 1][(int)x]->z != 1 && y - (int)y > 0.9965)
		init->dist->color = 0x0000ff;
	if (init->point[(int)y][(int)x]->z == 9)
		init->dist->color = 0xffffff;
}

double			adn(t_env *init, double xy2[2])
{
	double	size;
	double	dx;
	double	dy;
	double	x;
	double	y;

	size = fabs(xy2[1] - init->posinity);
	if (fabs(xy2[0] - init->posinitx) >= size)
		size = fabs(xy2[0] - init->posinitx);
	size *= 300;
	dx = (xy2[0] - init->posinitx) / size;
	dy = (xy2[1] - init->posinity) / size;
	x = init->posinitx + 0.1;
	y = init->posinity + 0.1;
	while (init->point[(int)y][(int)x] && init->point[(int)y][(int)x]->z != 1 &&
	init->point[(int)y][(int)x]->z != 9)
	{
		x += dx;
		y += dy;
	}
	init->dist->distval = sqrt((x - init->posinitx) * (x - init->posinitx) +
	(y - init->posinity) * (y - init->posinity));
	color_code(init, x, y);
	return (init->dist->distval);
}
