/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_timerev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:15:52 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 19:16:00 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

BOOL	cmp_timerev(t_elst *a, t_elst *b)
{
	return (a->lmtime < b->lmtime);
}
