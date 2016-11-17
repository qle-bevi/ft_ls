/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:28 by qle-bevi          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:56 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s1;
	unsigned char ch;

	s1 = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*(s1++) == ch)
			return (--s1);
	}
	return (NULL);
}
