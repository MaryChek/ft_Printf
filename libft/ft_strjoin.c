/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:20:40 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/19 17:35:31 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((s3 = ft_strnew(len)))
		{
			s3 = ft_strcpy(s3, s1);
			s3 = ft_strcat(s3, s2);
			return (s3);
		}
	}
	return (NULL);
}
