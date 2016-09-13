/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:28:18 by nlagache          #+#    #+#             */
/*   Updated: 2016/01/20 16:56:26 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_list;
	t_list	*old;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new = f(lst);
	begin_list = new;
	while (lst->next)
	{
		old = new;
		lst = lst->next;
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
			return (NULL);
		new = f(lst);
		old->next = new;
	}
	return (begin_list);
}
