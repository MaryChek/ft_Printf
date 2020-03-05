/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:24:15 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/15 20:36:27 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*s)
		str[i++] = f(*s++);
	str[i] = '\0';
	return (str);
}
