/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elst_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:16:29 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 19:17:00 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	elst_del(t_elst *entry)
{
	free(entry->path);
	if (g_long_display)
	{
		free(entry->nlink);
		free(entry->strtime);
		free(entry->owner);
		free(entry->group);
	}
	if (entry->strsize)
		free(entry->strsize);
	if (entry->major)
	{
		free(entry->major);
		free(entry->minor);
	}
	free(entry);
}
