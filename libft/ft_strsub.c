/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:40:07 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/19 17:41:25 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*st;
	unsigned int	i;

	i = 0;
	st = (char *)s;
	if (s && (str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
	{
		while (st[start] && len-- > 0)
			str[i++] = st[start++];
		return (str);
	}
	return (NULL);
}
