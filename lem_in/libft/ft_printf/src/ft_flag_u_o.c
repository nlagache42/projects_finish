/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 13:44:38 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/21 15:55:03 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**		for 'u' / 'o' : take and cast arg
*/

char		*pf_ft_modifier_u_o(t_flag *f, va_list *ap)
{
	intmax_t	data;

	if (f->fla[12] == 1)
		data = (uintmax_t)va_arg(*ap, size_t);
	else if (f->fla[11] == 1)
		data = va_arg(*ap, uintmax_t);
	else if (f->fla[9] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (f->fla[10] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long);
	else if (f->fla[8] == 1)
		data = (uintmax_t)(unsigned short)va_arg(*ap, unsigned int);
	else if (f->fla[7] == 1)
		data = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else
		data = (uintmax_t)va_arg(*ap, unsigned int);
	if (f->spe == 'u')
		return (pf_ft_itoa_base(data, 10));
	if (f->spe == 'o')
		return (pf_ft_itoa_base(data, 8));
	return (NULL);
}

/*
**		for 'u' : Make mask and cast number
*/

int			pf_ft_handler_u(t_flag *f, va_list *ap)
{
	static int	mask_u[13] = {0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	pf_ft_apply_mask(f, mask_u);
	f->arg = pf_ft_modifier_u_o(f, ap);
	pf_ft_handler_numb(f);
	return (0);
}

/*
**		for 'o' : Make mask and cast number
*/

int			pf_ft_handler_o(t_flag *f, va_list *ap)
{
	static int	mask_o[13] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	pf_ft_apply_mask(f, mask_o);
	f->arg = pf_ft_modifier_u_o(f, ap);
	if (f->fla[0] == -1 && f->arg[0] != '0' && f->fla[2] == 1)
		f->fla[0] = 0;
	pf_ft_handler_numb(f);
	return (0);
}
