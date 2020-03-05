/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:24:05 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/16 19:27:45 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	int				i;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (n-- > 0)
	{
		dst1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			return (&dst1[i + 1]);
		i++;
	}
	return (NULL);
}
