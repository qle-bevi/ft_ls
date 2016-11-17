/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:27 by qle-bevi          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:55 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		nbr;
	int		size;
	char	*str;

	if (n == -2147483648 || n == 0)
		return (ft_strdup(!n ? "0" : "-2147483648"));
	nbr = n;
	size = ft_getdecade(nbr);
	str = ft_strnew(size + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		ft_pushchar(str, '-');
		n = -n;
	}
	nbr = ft_pow(10, size - 1);
	while (nbr > 0)
	{
		str = ft_pushchar(str, (n / nbr) + 48);
		n = n % nbr;
		nbr = nbr / 10;
	}
	return (str);
}
