/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <nlagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:01:24 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/21 17:25:34 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			pf_ft_wcharlen(wchar_t wchar)
{
	if (wchar <= 0x7f)
		return (1);
	else if (wchar <= 0x7ff)
		return (2);
	else if (wchar <= 0xffff)
		return (3);
	else
		return (4);
}
