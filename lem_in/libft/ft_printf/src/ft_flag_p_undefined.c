/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p_undefined.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:33:12 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/21 15:52:02 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**			for 'p' : Make mask, cast number
*/

int		pf_ft_handler_p(t_flag *f, va_list *ap)
{
	static int	mask_p[13] = {0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

	f->fla[2] = 1;
	pf_ft_apply_mask(f, mask_p);
	f->arg = pf_ft_strlwr(pf_ft_itoa_base((uintmax_t)va_arg(*ap, void*), 16));
	if (f->fla[0] == -1 && f->arg[0] == '0')
	{
		pf_ft_buf('0', f);
		pf_ft_buf('x', f);
	}
	else
		pf_ft_handler_numb(f);
	return (0);
}

/*
**			for 'undefined' : Make mask, cast char
*/

int		pf_ft_handler_undefined(t_flag *f)
{
	static int	mask_und[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};
	char		c[2];

	f->fla[0] = 0;
	if (f->spe == 0)
	{
		f->ret = 0;
		return (f->ret);
	}
	c[0] = f->spe;
	c[1] = '\0';
	f->arg = c;
	pf_ft_apply_mask(f, mask_und);
	return (pf_ft_handler_char(f));
}
