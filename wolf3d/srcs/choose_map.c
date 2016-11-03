/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 21:13:51 by nlagache          #+#    #+#             */
/*   Updated: 2016/10/11 09:44:19 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	*selectmaps(void)
{
	char		*maps[10];
	static	int	x = -1;

	x++;
	maps[0] = "map/wall";
	maps[1] = "map/test";
	maps[2] = "map/try";
	maps[3] = "map/1";
	maps[4] = "map/level1";
	maps[5] = "map/acc";
	maps[6] = "map/level2";
	maps[7] = "map/oc";
	maps[8] = "map/lab1";
	maps[9] = "map/end";
	return (maps[x]);
}
