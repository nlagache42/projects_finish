/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 18:21:54 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/19 18:22:15 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../inc/minilibx_macos/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIN_X 800
# define WIN_Y 600

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define POINTERMOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6

# define ESC 53
# define ITER_M 69
# define ITER_L 78
# define RESET 82
# define JULIA 8
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	char		*argv;

	void		*im;
	char		*imc;
	int			bpp;
	int			imlen;
	int			endi;

	int			i;
	int			x;
	int			y;

	float		x1;
	float		x2;
	float		y1;
	float		y2;

	int			iter_max;
	int			im_x;
	int			im_y;

	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	float		tmp;

	float		zoom;
	float		zoom_x;
	float		zoom_y;

	int			itm;
	int			res;
	int			bj;

	float		tmpx;
	float		tmpy;
	float		tmpx2;
	float		tmpy2;

}				t_env;

void			ft_ini_fract(t_env *e);
void			ft_ini_val_mandel(t_env *e);
void			ft_ini_val_julia(t_env *e);
void			ft_ini_val_bship(t_env *e);
void			ft_ini_val_mandelbis(t_env *e);

void			ft_print_fract(t_env *e);
void			ft_print_mandel(t_env *e);
void			ft_print_julia(t_env *e);
void			ft_print_bship(t_env *e);
void			ft_print_mandelbis(t_env *e);

int				ft_core(t_env *e);
int				ft_key_biding(int keycode, t_env *e);
int				ft_key_release(int keycode, t_env *e);
void			ft_do_key_ation(t_env *e);

void			ft_put_pixel(t_env *e, int x, int y, int color);
void			ft_print_settings(void);
void			ft_error(void);

int				ft_mouse_hook(int keycode, int x, int y, t_env *e);
int				ft_julia_hook(int x, int y, t_env *e);

void			ft_zoom_in(int x, int y, t_env *e);
void			ft_zoom_out(int x, int y, t_env *e);

#endif
