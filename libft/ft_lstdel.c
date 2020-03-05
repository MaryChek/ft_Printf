/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:06:17 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/18 22:26:10 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst && del)
		while (*alst)
		{
			tmp = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = tmp;
		}
}
