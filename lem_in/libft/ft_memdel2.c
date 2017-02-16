/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:45:57 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/03 16:46:28 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_memdel2(void ***ap)
{
	int		i;

	if (ap != NULL && *ap != NULL)
	{
		i = -1;
		while ((*ap)[++i])
			ft_memdel((void **)&(*ap)[i]);
		free(*ap);
		*ap = NULL;
	}
}
