/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elst_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:17:05 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 19:17:17 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elst	*elst_pop(t_elst **begin)
{
	t_elst *elem;

	if (!*begin)
		return (NULL);
	elem = *begin;
	*begin = elem->next;
	elem->next = NULL;
	return (elem);
}
