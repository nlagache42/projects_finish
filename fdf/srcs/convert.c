/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 12:38:55 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/13 11:50:13 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d	convert(t_3d dp1, float dx, float dy)
{
	t_2d p1;

	p1.x = dp1.x - dp1.y;
	p1.y = dp1.z + (dp1.x / dx) + (dp1.y / dy);
	return (p1);
}
