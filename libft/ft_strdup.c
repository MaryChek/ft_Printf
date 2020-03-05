/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:38:34 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/19 18:04:31 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*src2;
	int		n;

	if (!(src2 = ft_strnew(ft_strlen(src))))
		return (NULL);
	n = 0;
	while (src[n])
	{
		src2[n] = src[n];
		n++;
	}
	return (src2);
}
