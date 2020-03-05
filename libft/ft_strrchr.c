/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:58:00 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/15 20:33:01 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			n;
	unsigned char	t;
	char			*str;

	t = (unsigned char)c;
	n = ft_strlen(s) + 1;
	str = (char *)s;
	while (n--)
		if (str[n] == t)
			return (&str[n]);
	return (NULL);
}
