/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:27:34 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/19 17:48:12 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;

	if (size == 0 || (s = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	ft_bzero((void *)s, size);
	return ((void *)s);
}
