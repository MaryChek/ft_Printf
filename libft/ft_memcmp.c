/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:48:32 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/13 20:26:20 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s;
	unsigned char *t;

	s = (unsigned char *)s1;
	t = (unsigned char *)s2;
	while (n--)
		if (*s++ != *t++)
			return (*(s - 1) - *(t - 1));
	return (0);
}
