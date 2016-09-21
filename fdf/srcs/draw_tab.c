/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 18:09:29 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/12 11:52:01 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_tab(int x, int y, t_mlx *mlx)
{
	t_3d	tdp;
	t_2d	dp1;
	t_2d	dp2;

	tdp.x = x * mlx->offset;
	tdp.y = y * mlx->offset;
	tdp.z = mlx->tab[y][x] * mlx->summit;
	dp1 = convert(tdp, mlx->dx, mlx->dy);
	if (x + 1 < mlx->xmax && mlx->tab[y][x + 1] != 1000000)
	{
		tdp.x = (x + 1) * mlx->offset;
		tdp.y = y * mlx->offset;
		tdp.z = mlx->tab[y][x + 1] * mlx->summit;
		dp2 = convert(tdp, mlx->dx, mlx->dy);
		draw_lines(mlx, dp1, dp2, color(tdp));
	}
	if (y + 1 < mlx->ymax && mlx->tab[y + 1][x] != 1000000)
	{
		tdp.x = x * mlx->offset;
		tdp.y = (y + 1) * mlx->offset;
		tdp.z = mlx->tab[y + 1][x] * mlx->summit;
		dp2 = convert(tdp, mlx->dx, mlx->dy);
		draw_lines(mlx, dp1, dp2, color(tdp));
	}
}

void		mlx_draw(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < mlx->ymax)
	{
		x = 0;
		while (x < mlx->xmax && mlx->tab[y][x] != 1000000)
		{
			draw_tab(x, y, mlx);
			x++;
		}
		y++;
	}
}
