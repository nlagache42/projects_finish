/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:36:30 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/01 12:42:46 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list.h"

void	error(char *s1)
{
	ft_putstr(C_RED);
	ft_putstr(s1);
	ft_putstr(C_NONE);
	exit(1);
}
