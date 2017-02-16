/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:35:03 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/21 15:36:52 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** 		Put string in g_buf, display 'null' if arg = null
*/

void		pf_ft_display_arg(t_flag *f)
{
	int		i;
	size_t	len;

	if ((i = -1) && ((f->spe == 's' && f->fla[10] == 1) || f->spe == 'S' ||
		(f->spe == 'c' && f->fla[10] == 1) || f->spe == 'C'))
	{
		if (f->arg != NULL)
		{
			if (f->arg[0] == '\0' && (f->spe == 'C' ||
				(f->spe == 'c' && f->fla[10] == 1)))
				pf_ft_buf('\0', f);
			len = pf_ft_strlen(f->arg);
			while (len-- > 0)
				pf_ft_buf(f->arg[++i], f);
		}
		else if (f->fla[0] != -1)
			pf_ft_buf_null(f);
	}
	else
	{
		while (f->arg[++i] != '\0')
			pf_ft_buf(f->arg[i], f);
	}
	pf_ft_end(f);
}

/*
** 				Width - strlen(arg) : put ' ' or '0' if > 0
*/

void		pf_ft_zero_char(t_flag *f)
{
	int		nb_space;

	nb_space = f->fla[1] - pf_ft_strlen(f->arg);
	if ((f->spe == 'c' && f->arg[0] == 0) || (f->spe == 'C' && f->arg[0] == 0))
		nb_space--;
	while (nb_space-- > 0)
	{
		if (f->fla[3] == 1 && f->fla[0] <= 0)
			pf_ft_buf('0', f);
		else
			pf_ft_buf(' ', f);
	}
	pf_ft_display_arg(f);
}

/*
**			Flag '-' : put arg first and put ' '
*/

void		pf_ft_minus_char(t_flag *f)
{
	int		nb_space;

	nb_space = f->fla[1] - pf_ft_strlen(f->arg);
	if ((f->spe == 'c' && f->arg[0] == 0) || (f->spe == 'C' && f->arg[0] == 0))
		nb_space--;
	pf_ft_display_arg(f);
	while (nb_space-- > 0)
		pf_ft_buf(' ', f);
}

/*
**			if width > strlen(arg), parse if '-'
*/

void		pf_ft_width_char(t_flag *f)
{
	int		i;

	i = 0;
	if (f->arg)
		i = pf_ft_strlen(f->arg);
	if (i < f->fla[1])
	{
		if (f->fla[4] == 1)
			pf_ft_minus_char(f);
		else
			pf_ft_zero_char(f);
	}
	else
		pf_ft_display_arg(f);
}
