/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:50:21 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/18 19:45:46 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if (!(tmp->content = (void *)malloc(sizeof(size_t) * content_size)))
			return (NULL);
		tmp->content = ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}
