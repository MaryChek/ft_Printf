/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:08:47 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/18 23:49:12 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dellst(t_list **list)
{
	t_list	*tmp;

	if (list)
		while ((*list)->next)
		{
			tmp = (*list)->next;
			free((*list)->content);
			(void)((*list)->content_size);
			free(*list);
			*list = tmp;
		}
}
