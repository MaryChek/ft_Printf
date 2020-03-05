/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:27:56 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/19 17:31:24 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;

	if (dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (len--)
	{
		if (s < d)
			*(d + len) = *(s + len);
		else
			*d++ = *s++;
	}
	return (dst);
}
