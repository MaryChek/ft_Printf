/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:54:08 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/15 20:33:29 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *dst)
{
	if (*dst)
	{
		while (*str)
			if (!ft_memcmp(str++, dst, ft_strlen(dst)))
				return ((char *)(str - 1));
		return (NULL);
	}
	return ((char *)str);
}
