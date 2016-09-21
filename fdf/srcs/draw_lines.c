/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 12:27:15 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/15 11:51:27 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		einf(int *err, t_2d d, t_2d s, t_2d *dp1)
{
	*err += d.x;
	dp1->y = dp1->y + s.y;
}

static void		esup(int *err, t_2d d, t_2d s, t_2d *dp1)
{
	*err -= d.y;
	dp1->x = dp1->x + s.x;
}

static int		ft_abs(int nb)
{
	if (nb >= 0)
	{
		return (nb);
	}
	else
	{
		return (nb = nb * (-1));
	}
}

void			draw_lines(t_mlx *mlx, t_2d dp1, t_2d dp2, int color)
{
	t_2d	d;
	t_2d	s;
	int		err;
	int		e2;

	d.x = ft_abs(dp2.x - dp1.x);
	s.x = dp1.x < dp2.x ? 1 : -1;
	d.y = ft_abs(dp2.y - dp1.y);
	s.y = dp1.y < dp2.y ? 1 : -1;
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (!(dp1.x == dp2.x && dp1.y == dp2.y))
	{
		mlx_pixel_put(mlx->init, mlx->win, dp1.x + mlx->pwidth, dp1.y
		+ mlx->pheight, color);
		e2 = err;
		if (e2 > -d.x)
			esup(&err, d, s, &dp1);
		if (e2 < d.y)
			einf(&err, d, s, &dp1);
	}
	mlx_pixel_put(mlx->init, mlx->win, dp1.x + mlx->pwidth, dp1.y
	+ mlx->pheight, color);
}
