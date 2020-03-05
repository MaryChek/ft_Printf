/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:55:07 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/13 12:35:13 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char b;

	b = (unsigned char)c;
	while (*s && *s != b)
		s++;
	if (*s == b)
		return ((char *)s);
	return (NULL);
}
