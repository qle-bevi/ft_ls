/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:13:53 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/10 14:59:45 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/xattr.h>
#include <unistd.h>
#include "ft_ls.h"

static char		g_buffer[500] = {0};

static void		add_permissions(t_type type, mode_t mode, BOOL hxattrs)
{
	static char cletters[] = "pcdb-ls-";

	g_buffer[0] = cletters[type];
	g_buffer[1] = mode & S_IRUSR ? 'r' : '-';
	g_buffer[2] = mode & S_IWUSR ? 'w' : '-';
	if (mode & S_ISUID)
		g_buffer[3] = mode & S_IXUSR ? 's' : 'S';
	else
		g_buffer[3] = mode & S_IXUSR ? 'x' : '-';
	g_buffer[4] = mode & S_IRGRP ? 'r' : '-';
	g_buffer[5] = mode & S_IWGRP ? 'w' : '-';
	if (mode & S_ISGID)
		g_buffer[6] = mode & S_IXGRP ? 's' : 'S';
	else
		g_buffer[6] = mode & S_IXGRP ? 'x' : '-';
	g_buffer[7] = mode & S_IROTH ? 'r' : '-';
	g_buffer[8] = mode & S_IWOTH ? 'w' : '-';
	if (mode & S_ISVTX)
		g_buffer[9] = mode & S_IXOTH ? 't' : 'T';
	else
		g_buffer[9] = mode & S_IXOTH ? 'x' : '-';
	g_buffer[10] = hxattrs ? '@' : ' ';
}

static void		pad(char **head, char *str, int pad, BOOL right)
{
	int i;

	i = 0;
	if (!right)
		while (i < pad)
		{
			**head = ' ';
			++i;
			*head += 1;
		}
	while (*str)
	{
		**head = *str;
		*head += 1;
		++str;
	}
	if (right)
		while (i < pad)
		{
			**head = ' ';
			++i;
			*head += 1;
		}
}

static void		add_size(char **head, t_elstinfos *infos, t_elst *entry)
{
	unsigned int offset;

	if (entry->type == EBLK || entry->type == ECHR)
	{
		pad(head, entry->major,
		infos->max_major - ft_strlen(entry->major) + 1, FALSE);
		**head = ',';
		*head += 1;
		pad(head, entry->minor,
		infos->max_minor - ft_strlen(entry->minor) + 3, FALSE);
	}
	else
	{
		offset = (infos->max_size - ft_strlen(entry->strsize));
		offset += infos->max_major + infos->max_minor + 4;
		pad(head, entry->strsize, offset, FALSE);
	}
	**head = ' ';
	*head += 1;
}

void			print_entry_long(t_elst *entry)
{
	t_elstinfos	*infos;
	char		*head;

	infos = &g_elstinfos;
	head = g_buffer + 11;
	add_permissions(entry->type, entry->mode, entry->hxattrs);
	pad(&head, entry->nlink,
	infos->max_lnks - ft_strlen(entry->nlink) + 1, FALSE);
	*(head++) = ' ';
	pad(&head, entry->owner,
	infos->max_owner - ft_strlen(entry->owner) + 1, TRUE);
	*(head++) = ' ';
	pad(&head, entry->group,
	infos->max_group - ft_strlen(entry->group) + 1, TRUE);
	add_size(&head, infos, entry);
	*(head++) = ' ';
	ft_strcat(head, entry->strtime);
	ft_strcat(head, " ");
	write(1, g_buffer, ft_strlen(g_buffer));
	print_entry(entry);
	ft_strclr(g_buffer);
}
