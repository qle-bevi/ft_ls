/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 21:13:16 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 21:13:57 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	ft_lstgot(t_list *list, t_list *elem)
{
	while (list)
	{
		if (list == elem)
			return (TRUE);
		list = list->next;
	}
	return (FALSE);
}
