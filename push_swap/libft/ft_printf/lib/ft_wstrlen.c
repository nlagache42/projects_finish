/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <nlagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:59:17 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/21 17:23:49 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t		pf_ft_wbytelen(wchar_t *ws)
{
	size_t	len;
	size_t	bytelen;

	len = pf_ft_wstrlen(ws);
	bytelen = 0;
	while (len > 0)
	{
		bytelen += pf_ft_wcharlen(*ws);
		ws++;
		len--;
	}
	return (bytelen);
}

size_t		pf_ft_wstrlen(wchar_t *ws)
{
	size_t	len;

	len = 0;
	if (!ws)
		return (0);
	while (*(ws++))
		len++;
	return (len);
}
