/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:31 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/01/13 16:51:33 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		start;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	len--;
	while (s[start] == '\n' || s[start] == '\t' || s[start] == ' ')
	{
		start++;
		if (!s[start])
			return (ft_strnew(0));
	}
	while (s[len] == '\n' || s[len] == '\t' || s[len] == ' ')
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
