/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:49:01 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/18 23:26:31 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *tmp;

	if (!(lst && f))
		return (NULL);
	tmp = f(lst);
	list = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
		{
			ft_dellst(&list);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (list);
}
