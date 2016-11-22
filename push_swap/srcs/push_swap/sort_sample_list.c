/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sample_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:11:05 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 15:59:32 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

static int		fusion_help(int *begin2, int *cpt2, int mid, int begin)
{
	*begin2 = mid + 1;
	*cpt2 = *begin2;
	return (begin);
}

static void		fusion(int *list, int begin, int mid, int end)
{
	int		*tmp;
	int		begin2;
	int		cpt1;
	int		cpt2;
	int		i;

	tmp = (int *)ft_memalloc(sizeof(int) * (mid - begin + 1));
	cpt1 = fusion_help(&begin2, &cpt2, mid, begin);
	i = begin - 1;
	while (++i <= mid)
		tmp[i - begin] = list[i];
	i = begin - 1;
	while (++i <= end)
	{
		if (cpt1 == begin2)
			break ;
		else if (cpt2 == (end + 1))
			list[i] = tmp[cpt1++ - begin];
		else if (tmp[cpt1 - begin] < list[cpt2])
			list[i] = tmp[cpt1++ - begin];
		else
			list[i] = list[cpt2++];
	}
	ft_memdel((void **)&tmp);
}

static void		fusion_sort(int *list, int beg, int end)
{
	int		mid;

	if (end != beg)
	{
		mid = (end + beg) / 2;
		fusion_sort(list, beg, mid);
		fusion_sort(list, mid + 1, end);
		fusion(list, beg, mid, end);
	}
}

void			sort_sample_list(int *list, int beg, int end)
{
	if (end > 0)
		fusion_sort(list, beg, end);
}
