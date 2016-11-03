/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:12:21 by nlagache          #+#    #+#             */
/*   Updated: 2016/10/11 09:36:40 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	t_point		*ft_pointnew(int x, int y, int z, int coln)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		error("error : ft_pointnew");
	point->x = x;
	point->y = y;
	point->z = z;
	point->sizeline = 0;
	if (x == 0)
	{
		point->sizecol = coln;
		if (z != 1 && z != 9)
			error("error : no wall");
	}
	if (y == 0)
	{
		if (z != 1 && z != 9)
			error("error : no wall");
	}
	return (point);
}

static	int			verif_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			error("error : verif_str");
		i++;
	}
	return (1);
}

t_point				**init_point(t_env *init, char *line, int j)
{
	int		i;
	int		coln;
	char	**s;
	t_point	**point;

	i = 0;
	coln = ft_countcara(line);
	s = ft_strsplit(line, 32);
	if (!(point = (t_point **)malloc(sizeof(*point) * (coln + 1))))
		error("error : init_point");
	while (i < coln)
	{
		verif_str(s[i]);
		point[i] = ft_pointnew(i, j, ft_atoi(s[i]), coln);
		if (point[i]->z == 42 && (init->posinitx = i) == i)
			init->posinity = j;
		free(s[i]);
		i++;
	}
	if (i == 0)
		error("error : i == 0");
	free(s);
	return (point);
}
