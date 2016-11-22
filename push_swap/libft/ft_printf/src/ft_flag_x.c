/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:12:22 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/26 09:28:57 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**		for 'x' / 'X' : take and cast arg
*/

char			*pf_ft_modifier_x(t_flag *f, va_list *ap)
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
	if (f->spe == 'X')
		return (pf_ft_itoa_base(data, 16));
	if (f->spe == 'x')
		return (pf_ft_strlwr(pf_ft_itoa_base(data, 16)));
	return (NULL);
}

/*
**		for 'x' : Make mask and cast number
*/

int				pf_ft_handler_wx(t_flag *f, va_list *ap)
{
	static int	mask_wx[13] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	pf_ft_apply_mask(f, mask_wx);
	f->arg = pf_ft_modifier_x(f, ap);
	if (f->fla[0] == -1 && f->arg[0] != '0' && f->fla[2] == 1)
		f->fla[0] = 0;
	pf_ft_handler_numb(f);
	return (0);
}

/*
**		for 'X' : Make mask and cast number
*/

int				pf_ft_handler_x(t_flag *f, va_list *ap)
{
	static int	mask_x[13] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	pf_ft_apply_mask(f, mask_x);
	f->arg = pf_ft_modifier_x(f, ap);
	if (f->fla[0] == -1 && f->arg[0] != '0' && f->fla[2] == 1)
		f->fla[0] = 0;
	pf_ft_handler_numb(f);
	return (0);
}
