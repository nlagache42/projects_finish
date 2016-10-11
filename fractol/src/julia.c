/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 20:45:33 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/19 18:25:45 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_print_julia(t_env *e)
{
	e->x = -1;
	while (++e->x < e->im_x)
	{
		e->y = -1;
		while (++e->y < e->im_y)
		{
			e->z_r = e->x / e->zoom + e->x1;
			e->z_i = e->y / e->zoom + e->y1;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			if (e->i == e->iter_max)
				ft_put_pixel(e, e->x, e->y, 0xFFFFFF);
			else
				ft_put_pixel(e, e->x, e->y, e->i * 1899750);
		}
	}
}

int		ft_julia_hook(int x, int y, t_env *e)
{
	if (!(ft_strcmp(e->argv, "julia")) &&
		x <= WIN_X && y <= WIN_Y && x > 0 && y > 0 && e->bj == 0)
	{
		e->c_r = (float)(x + 400 - WIN_X) / 300;
		e->c_i = (float)(y + 320 - WIN_Y) / 300;
	}
	return (1);
}
