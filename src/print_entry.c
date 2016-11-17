/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 20:17:12 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 21:10:33 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"

void		print_link(char *path)
{
	static char buffer[200] = {0};

	if (readlink(path, buffer, 200) != -1)
	{
		ft_putstr(" -> ");
		ft_putstr(buffer);
	}
	ft_strclr(buffer);
}

static BOOL	is_executable(mode_t mode)
{
	if (mode & S_IXUSR || mode & S_IXGRP || mode & S_IXOTH)
		return (TRUE);
	return (FALSE);
}

void		print_entry(t_elst *entry)
{
	static char *colors[] = {CFIFO, CCHR, CDIR, CBLK, CREG, CLNK, CSOCK, CWHT};
	char		*color;

	color = colors[entry->type];
	if (entry->type == EREG && is_executable(entry->mode))
		write(1, "\033[31m", 5);
	else if (color)
		write(1, color, ft_strlen(color));
	ft_putstr(entry->name);
	write(1, CDEF, 5);
	if (g_long_display && entry->type == ELNK)
		print_link(entry->path);
	ft_putchar('\n');
}
