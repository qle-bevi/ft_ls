/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:31 by qle-bevi          #+#    #+#             */
/*   Updated: 2015/11/29 23:17:00 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (!*s2)
		return (char *)(s1);
	i = 0;
	j = 0;
	while (s1[i] && i < n)
	{
		while (s2[j] && s1[i + j] == s2[j] && i + j < n)
			j++;
		if (j && !s2[j])
			return (char *)(s1 + i);
		j = 0;
		i++;
	}
	return (NULL);
}
