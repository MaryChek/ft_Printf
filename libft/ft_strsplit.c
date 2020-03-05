/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:30:54 by rtacos            #+#    #+#             */
/*   Updated: 2019/09/19 18:27:33 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tg;
	size_t	i;
	size_t	w;
	size_t	l;

	i = 0;
	if (!s || !(tg = (char **)malloc(sizeof(char*) * (ft_word(s, c) + 1))))
		return (NULL);
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			l = ft_letter(s, c, i);
			if (!(tg[w++] = ft_strsub(s, i, l)))
			{
				ft_freetg(tg, w - 1);
				return (NULL);
			}
			i = i + l - 1;
		}
		i++;
	}
	tg[w] = NULL;
	return (tg);
}
