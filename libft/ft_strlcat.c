/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:02:32 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/15 20:35:48 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	k;

	j = 0;
	i = 0;
	while (dst[i] && i < size)
		i++;
	k = i;
	while (src[j] && k < (size - 1) && size)
		dst[k++] = src[j++];
	if (k < size)
		dst[k] = '\0';
	return (ft_strlen(src) + i);
}
