/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:28:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 19:34:14 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <uuid/uuid.h>
#include <sys/xattr.h>
#include "ft_ls.h"

static t_type	get_type(mode_t mode)
{
	static mode_t	modes[] = MODES;
	int				i;

	i = 0;
	while (i < 7)
	{
		if ((mode & S_IFMT) == modes[i])
			return (i);
		++i;
	}
	return (7);
}

static char		*get_name(char *path)
{
	int i;

	i = ft_strlen(path);
	while (--i)
		if (path[i] == '/')
			return (path + i + 1);
	return (path);
}

static void		add_size(t_elst *entry, STAT *estat)
{
	if (entry->type == EBLK || entry->type == ECHR)
	{
		entry->minor = ft_itoa(minor(estat->st_rdev));
		entry->major = ft_itoa(major(estat->st_rdev));
	}
	entry->strsize = ft_itoa(estat->st_size);
}

static void		load_external_infos(t_elst *entry, STAT *estat)
{
	struct passwd	*pwd;
	struct group	*grp;
	time_t			current_time;
	char			*timeptr;

	timeptr = ctime(&estat->st_mtime);
	current_time = time(&current_time);
	entry->nlink = ft_itoa(estat->st_nlink);
	pwd = getpwuid(estat->st_uid);
	grp = getgrgid(estat->st_gid);
	entry->owner = (pwd) ? ft_strdup(pwd->pw_name) : ft_itoa(estat->st_uid);
	entry->group = (grp) ? ft_strdup(grp->gr_name) : ft_itoa(estat->st_gid);
	entry->strtime = ft_strnew(12);
	entry->blocks = estat->st_blocks;
	ft_memcpy(entry->strtime, timeptr + 4, 7);
	if (SHLDPRYR(current_time, estat->st_mtime))
		ft_memcpy(entry->strtime + 7, timeptr + 19, 5);
	else
		ft_memcpy(entry->strtime + 7, timeptr + 11, 5);
	add_size(entry, estat);
	entry->hxattrs = listxattr(entry->path, NULL, 0, 0) > 0;
}

t_elst			*new_entry(char *path, BOOL name_is_path)
{
	STAT	estat;
	t_elst	*entry;

	if (lstat(path, &estat) == -1)
	{
		print_error(path);
		free(path);
		return (NULL);
	}
	if (!(entry = (t_elst *)ft_memalloc(sizeof(t_elst))))
		ft_errexit("malloc failed");
	entry->name = (name_is_path) ? path : get_name(path);
	entry->path = path;
	entry->type = get_type(estat.st_mode);
	entry->mode = estat.st_mode;
	if (g_need_size)
		entry->size = estat.st_size;
	if (g_long_display)
		load_external_infos(entry, &estat);
	entry->lmtime = estat.st_mtime;
	entry->next = NULL;
	return (entry);
}
