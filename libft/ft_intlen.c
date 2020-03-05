/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:59:14 by rtacos            #+#    #+#             */
/*   Updated: 2020/03/05 21:21:51 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(LL_int n)
{
	size_t	i;

	i = 0;
	if (!n)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
