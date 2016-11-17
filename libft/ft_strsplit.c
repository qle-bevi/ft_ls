/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:31 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/01/13 16:51:21 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	int		wi;
	char	**as;

	if (!s)
		return (NULL);
	as = ft_memalloc(sizeof(as) * (ft_countwords(s, c) + 1));
	i = 0;
	len = 0;
	wi = 0;
	if (!as)
		return (NULL);
	while (s[i])
	{
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len)
			as[wi++] = ft_strsub(s, i, len);
		i += len ? len : 1;
		len = 0;
	}
	as[wi] = NULL;
	return (as);
}
