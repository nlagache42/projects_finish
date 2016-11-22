/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:44:33 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/03 16:44:59 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisdigit(char *str)
{
	int		i;
	int		end;

	i = -1;
	end = 0;
	while (str[++i] == ' ')
		;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) && end == 0)
			i++;
		else if (str[i] == ' ' && end == 0)
			end = 1;
		else
			return (0);
	}
	return (1);
}
