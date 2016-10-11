/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 11:33:34 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/19 18:42:35 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	int *tmp;

	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->imc[(y * e->imlen) + (x * (e->bpp / 8))];
	*tmp = color;
}

void	ft_print_settings(void)
{
	ft_putstr("      -------------------------------------------------\n");
	ft_putstr("      |       KEY        |           ACTION           |\n");
	ft_putstr("      -------------------------------------------------\n");
	ft_putstr("      |      'ESC'       |          exit              |\n");
	ft_putstr("      |   'left click'   |          zoom +            |\n");
	ft_putstr("      |  'right click'   |          zoom -            |\n");
	ft_putstr("      |       '+'        |    increase iteration      |\n");
	ft_putstr("      |       '-'        |    decrease iteration      |\n");
	ft_putstr("      | '1 - 2 - 3 or 4' | switch to an other fractal |\n");
	ft_putstr("      |       'C'        |   pause the modifications  |\n");
	ft_putstr("      |                  |          of Julia          |\n");
	ft_putstr("      |     numpad '0'   |           reset            |\n");
	ft_putstr("      ------------------------------------------------\n\n\n");
}

void	ft_error(void)
{
	ft_putstr_fd("Error, not enought argument : \n", 2);
	ft_putstr_fd("               ", 1);
	ft_putstr_fd("               1) mandelbrot\n", 2);
	ft_putstr_fd("               ", 2);
	ft_putstr_fd("               2) julia\n", 2);
	ft_putstr_fd("               ", 2);
	ft_putstr_fd("               3) burning-ship\n", 2);
	ft_putstr_fd("               ", 2);
	ft_putstr_fd("               4) mandelbis\n", 2);
	exit(1);
}
