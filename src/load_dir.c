/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:19:37 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 19:22:05 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_ls.h"

static char	g_buffer[500] = {0};

static void	load_buffer(char *path)
{
	int len;

	len = ft_strlen(path);
	ft_memcpy(g_buffer, path, (size_t)len);
	ft_memcpy(g_buffer + len, "/\0", 2);
}

BOOL		load_dir(char *path, t_elst **entries, BOOL all)
{
	DIR		*dirp;
	DIRE	*dire;
	t_elst	*last;
	t_elst	*entry;

	last = NULL;
	load_buffer(path);
	if (!(dirp = opendir(path)))
	{
		print_error(path);
		return (FALSE);
	}
	while ((dire = readdir(dirp)))
		if (all || dire->d_name[0] != '.')
			if ((entry = new_entry(ft_strjoin(g_buffer, dire->d_name), FALSE)))
				last = elst_add(entries, last, entry);
	closedir(dirp);
	free(dire);
	return (TRUE);
}
