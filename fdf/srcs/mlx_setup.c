/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 16:31:22 by nlagache          #+#    #+#             */
/*   Updated: 2016/07/22 11:57:22 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		norme_key(int keycode, t_mlx *mlx)
{
	if (keycode == 0)
		mlx->pwidth = mlx->pwidth - 30;
	if (keycode == 2)
		mlx->pwidth = mlx->pwidth + 30;
	if (keycode == 1)
		mlx->pheight = mlx->pheight + 30;
	if (keycode == 13)
		mlx->pheight = mlx->pheight - 30;
	if (keycode == 123 && mlx->dx < 3.5)
		mlx->dx = mlx->dx + 0.1;
	if (keycode == 124 && mlx->dx > 0.5)
		mlx->dx = mlx->dx - 0.1;
	if (keycode == 126 && mlx->dy < 3.5)
		mlx->dy = mlx->dy + 0.1;
	if (keycode == 125 && mlx->dy > 0.5)
		mlx->dy = mlx->dy - 0.1;
	return (1);
}

static int		key_hook(int keycode, t_mlx *mlx)
{
	void	*ptr;

	ptr = mlx_new_image(mlx->init, mlx->width, mlx->height);
	mlx_put_image_to_window(mlx->init, mlx->win, ptr, 0, 0);
	if (keycode == 53)
		exit(0);
	if (keycode == 69 && mlx->offset < 30)
		mlx->offset++;
	if (keycode == 78 && mlx->offset > 1)
		mlx->offset--;
	norme_key(keycode, mlx);
	mlx_draw(mlx);
	return (0);
}

static void		mlx_setup(t_mlx *mlx, int xmax, int ymax, int **tab)
{
	mlx->dx = 2.0;
	mlx->dy = 2.0;
	mlx->height = 720;
	mlx->width = 1080;
	mlx->pwidth = mlx->width / 2;
	mlx->pheight = mlx->height / 4;
	mlx->xmax = xmax;
	mlx->ymax = ymax;
	if (mlx->zmax != 0)
		mlx->summit = -10 / mlx->zmax * 2;
	mlx->offset = (mlx->width + mlx->height) / sqrt(mlx->xmax
			* mlx->xmax + mlx->ymax * mlx->ymax) * 0.25;
	mlx->tab = tab;
}

static int		expose_hook(t_mlx *mlx)
{
	mlx_draw(mlx);
	return (0);
}

int				activate_mlx(int **tab, int xmax, int ymax, int zmax)
{
	t_mlx	mlx;

	mlx.zmax = zmax;
	mlx_setup(&mlx, xmax, ymax, tab);
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, mlx.width, mlx.height, "FdF");
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
