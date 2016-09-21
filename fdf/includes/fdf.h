/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 14:04:16 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/14 14:04:21 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <../minilibx_macos/mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct		s_mlx
{
	void			*init;
	void			*win;
	int				height;
	int				width;
	int				offset;
	int				summit;
	int				**tab;
	float			dx;
	float			dy;
	int				xmax;
	int				ymax;
	int				zmax;
	int				pheight;
	int				pwidth;
}					t_mlx;

typedef struct		s_env
{
	int				x;
	int				y;
	int				i;
	int				j;
}					t_env;

typedef struct		s_2d
{
	int				x;
	int				y;
}					t_2d;

typedef struct		s_3d
{
	int				x;
	int				y;
	int				z;
}					t_3d;

typedef struct		s_list2
{
	char			**map;
	struct s_list2	*next;
}					t_list2;

t_2d				convert(t_3d dp1, float dx, float dy);
int					color(t_3d tdp);
void				draw_lines(t_mlx *mlx, t_2d dp1, t_2d dp2, int color);
int					list_lenght(t_list2 *begin_list);
t_list2				*read_file(char *str);
t_list2				*coordmap(char *line, t_list2 *list);
void				mlx_draw(t_mlx *mlx);
int					list_to_tab(int ***tab, t_list2 *list,
					int list_lenght, int *z);
int					activate_mlx(int **tab, int xmax, int ymax, int zmax);
void				error(char *str);
#endif
