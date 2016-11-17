/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:29 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/01/13 16:48:27 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!c)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
