/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:16:55 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/19 18:25:15 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_zoom_out(int x, int y, t_env *e)
{
	if (e->zoom > 250)
	{
		e->zoom /= 2;
		e->tmpx = e->x1 + x * (e->x2 - e->x1) / WIN_X;
		e->tmpy = e->y1 + y * (e->y2 - e->y1) / WIN_Y;
		e->tmpx2 = e->x1;
		e->tmpy2 = e->y1;
		e->x1 = e->tmpx - (e->x2 - e->x1);
		e->x2 = e->tmpx + (e->x2 - e->tmpx2);
		e->y1 = e->tmpy - (e->y2 - e->y1);
		e->y2 = e->tmpy + (e->y2 - e->tmpy2);
	}
}

void	ft_zoom_in(int x, int y, t_env *e)
{
	e->zoom *= 2;
	e->tmpx = e->x1 + x * (e->x2 - e->x1) / WIN_X;
	e->tmpy = e->y1 + y * (e->y2 - e->y1) / WIN_Y;
	e->tmpx2 = e->x1;
	e->tmpy2 = e->y1;
	e->x1 = e->tmpx - (e->x2 - e->x1) / 4;
	e->x2 = e->tmpx + (e->x2 - e->tmpx2) / 4;
	e->y1 = e->tmpy - (e->y2 - e->y1) / 4;
	e->y2 = e->tmpy + (e->y2 - e->tmpy2) / 4;
}

int		ft_mouse_hook(int keycode, int x, int y, t_env *e)
{
	if (y > 0)
	{
		if (keycode == 1 || keycode == 5)
			ft_zoom_in(x, y, e);
		if (keycode == 2 || keycode == 4)
			ft_zoom_out(x, y, e);
	}
	return (1);
}
