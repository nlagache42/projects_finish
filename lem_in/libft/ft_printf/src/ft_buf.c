/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:37:12 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/21 15:42:28 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** 				Init g_buf with \0
*/

void				pf_ft_bufset(void)
{
	int				n;

	n = 0;
	while (n < 4096)
	{
		g_buf[n] = '\0';
		n++;
	}
	g_i = 0;
}

/*
** 				Display g_buf > g_i
*/

void				pf_ft_display(t_flag *f)
{
	f->ret += write(1, g_buf, g_i);
	pf_ft_bufset();
}

/*
** 				Display (null)
*/

void				pf_ft_buf_null(t_flag *f)
{
	static char		str[6] = "(null)";
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		pf_ft_buf(str[i], f);
		i++;
	}
}

/*
** 			Put in g_buf for max 4095 char and display if full
*/

void				pf_ft_buf(char c, t_flag *f)
{
	g_buf[g_i] = c;
	g_i++;
	if (g_i == 4096)
		pf_ft_display(f);
}
