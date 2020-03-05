/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:18:14 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/18 19:06:25 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	size_t			max;
	unsigned int	i;

	max = ft_intlen(n);
	if (n < 0)
	{
		i = (unsigned int)(n * (-1));
		max++;
	}
	else
		i = (unsigned int)(n);
	if (!(str = ft_strnew(max)))
		return (NULL);
	while (max)
	{
		str[--max] = (i % 10) + 48;
		i = i / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
