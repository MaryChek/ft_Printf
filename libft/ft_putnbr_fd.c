/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:13:08 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/17 18:11:43 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	int				b;

	b = 1000000000;
	if ((i = (unsigned int)n) == 0)
		b = 1;
	if (n < 0)
	{
		i = (unsigned int)(n * -1);
		ft_putchar_fd('-', fd);
	}
	while (i && (i / b) == 0)
		b = b / 10;
	while (b)
	{
		ft_putchar_fd(i / b + '0', fd);
		i = i % b;
		b = b / 10;
	}
}
