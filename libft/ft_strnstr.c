/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:27:51 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/16 13:50:15 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *dst, size_t len)
{
	size_t l;

	if ((l = ft_strlen(dst)))
	{
		if (!(ft_strlen(str) < l || len < l))
		{
			while (*str && len-- >= l)
				if (!ft_memcmp(str++, dst, l))
					return ((char *)(str - 1));
		}
		return (NULL);
	}
	return ((char *)str);
}
