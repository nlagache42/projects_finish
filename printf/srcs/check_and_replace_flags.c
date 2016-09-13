/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_replace_flags.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:15:39 by nlagache          #+#    #+#             */
/*   Updated: 2016/08/31 06:59:58 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_valid(const char *format, int i)
{
	char	*str_arg;

	str_arg = ft_strdup("cdisouxpXCDSOU 0123456789-+.#*lhjz");
	while (ft_strchr(str_arg, format[i]) == 0)
	{
		i++;
		if (format[i] == '\0')
		{
			free(str_arg);
			return (0);
		}
	}
	free(str_arg);
	return (1);
}
