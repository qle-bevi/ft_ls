/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:28 by qle-bevi          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:56 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	size_t			i;

	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	if (!n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		uc_dst[i] = uc_src[i];
		if (uc_src[i] == (unsigned char)c)
			return (uc_dst + i + 1);
		i++;
	}
	return (NULL);
}
