/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 13:19:02 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/20 11:27:28 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color(t_3d tdp)
{
	if (-tdp.z < 0)
		return (0x0000CC);
	if (-tdp.z >= 0 && -tdp.z < 2)
		return (0xFFFFFF);
	if (-tdp.z >= 2 && -tdp.z < 3)
		return (0x33FF33);
	if (-tdp.z >= 3 && -tdp.z < 10)
		return (0xCC00FF);
	if (-tdp.z >= 10 && -tdp.z < 30)
		return (0xFF0066);
	if (-tdp.z >= 30 && -tdp.z < 60)
		return (0xFF0033);
	return (0xFF0000);
}
