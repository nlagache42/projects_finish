/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:28:54 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 15:44:55 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

int		main(int ac, char **av)
{
	t_lst	*param;
	char	*line;
	t_env	*tmp2;

	if (ac < 2)
		exit(0);
	if (check_arg(ac, av) == 0)
		exit(write(1, "Error\n", 6));
	line = ft_strnew(BUFFSIZE);
	put_in_dblist(ac, av, &tmp2);
	while (get_next_line(STDIN, &line))
		param = add_back_clist(param, line);
	sort_param(param, &tmp2);
	check_sort(tmp2);
	return (0);
}
