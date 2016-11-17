/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elst_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:16:08 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 19:16:21 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elst	*elst_add(t_elst **begin, t_elst *last, t_elst *new)
{
	if (!*begin)
		return (*begin = new);
	return (last->next = new);
}
