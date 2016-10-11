/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 18:23:58 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/19 18:24:03 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_key_biding(int keycode, t_env *e)
{
	if (keycode == ITER_M || keycode == ITER_L)
		e->itm = (keycode == ITER_M ? 1 : -1);
	if (keycode == RESET)
		e->res = 1;
	if (keycode == JULIA)
		e->bj = 1;
	if (keycode == ONE || keycode == TWO)
		e->argv = (keycode == ONE ? "mandelbrot" : "julia");
	if (keycode == THREE || keycode == FOUR)
		e->argv = (keycode == THREE ? "burning-ship" : "mandelbis");
	if (keycode == ONE || keycode == TWO || keycode == THREE || keycode == FOUR)
		ft_ini_fract(e);
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == ITER_M || keycode == ITER_L)
		e->itm = 0;
	if (keycode == RESET)
		e->res = 0;
	if (keycode == JULIA)
		e->bj = 0;
	return (0);
}

void	ft_do_key_action(t_env *e)
{
	if (e->itm == -1 && e->iter_max > 10)
		e->iter_max -= 10;
	if (e->itm == 1)
		e->iter_max += 10;
	if (e->res == 1)
		ft_ini_fract(e);
}

int		ft_core(t_env *e)
{
	mlx_destroy_image(e->mlx, e->im);
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_do_key_action(e);
	ft_print_fract(e);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	return (1);
}
