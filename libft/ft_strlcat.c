/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:30 by qle-bevi          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:59 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t lol;

	i = 0;
	while (dst[i])
		i++;
	if (!i)
	{
		while (src[i++])
			dst[i - 1] = src[i - 1];
		dst[i - 1] = '\0';
		return (ft_strlen(src));
	}
	if (size <= i)
		return (size + ft_strlen(src));
	lol = 0;
	while (i + lol + 1 < size)
	{
		dst[i + lol] = src[lol];
		lol += 1;
	}
	dst[i + lol] = '\0';
	return ((size + i) - (size - i));
}
