/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:20:30 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/19 18:39:01 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	if (dst != src)
	{
		s1 = (unsigned char *)dst;
		s2 = (unsigned char *)src;
		while (n--)
			*s1++ = *s2++;
	}
	return (dst);
}
