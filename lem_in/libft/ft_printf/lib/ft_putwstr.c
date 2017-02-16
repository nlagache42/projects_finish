/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <nlagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:44:32 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/21 17:24:49 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		pf_ft_putwstr(wchar_t *ws)
{
	size_t	len;

	len = pf_ft_wstrlen(ws);
	while (len > 0)
	{
		pf_ft_putwchar(*ws, f);
		ws++;
		len--;
	}
}
