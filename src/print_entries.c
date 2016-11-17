/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:59:33 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/10 15:11:24 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	(*g_print)(t_elst *) = print_entry;

static void	check_minor_major(t_elstinfos *infos, t_elst *current)
{
	int	len;

	if (current->type != EBLK)
		return ;
	if ((len = ft_strlen(current->minor)) > infos->max_minor)
		infos->max_minor = len;
	if ((len = ft_strlen(current->major)) > infos->max_major)
		infos->max_major = len;
}

static void	handle_long_display(t_elst *current, BOOL print_total)
{
	t_elstinfos *infos;
	int			len;

	ft_bzero((infos = &g_elstinfos), sizeof(t_elstinfos));
	while (current)
	{
		infos->total += current->blocks;
		if ((len = ft_strlen(current->nlink)) > infos->max_lnks)
			infos->max_lnks = len;
		if ((len = ft_strlen(current->owner)) > infos->max_owner)
			infos->max_owner = len;
		if ((len = ft_strlen(current->group)) > infos->max_group)
			infos->max_group = len;
		check_minor_major(infos, current);
		if ((len = ft_strlen(current->strsize)) > infos->max_size)
			infos->max_size = len;
		current = current->next;
	}
	if (print_total)
	{
		ft_putstr("total ");
		ft_putnbr(infos->total);
		ft_putchar('\n');
	}
}

void		set_print_entry_func(void (*func)(t_elst *))
{
	g_print = func;
}

void		print_entries_simple(t_elst **entries)
{
	t_elst *current;

	if (!*entries)
		return (g_dirs ? ft_putchar('\n') : (void)0);
	if (g_long_display)
		handle_long_display(*entries, (*entries)->next != NULL);
	while ((current = elst_pop(entries)))
	{
		g_print(current);
		elst_del(current);
	}
	if (g_dirs)
		ft_putchar('\n');
}

void		print_entries_rec(t_elst **entries)
{
	t_elst *current;
	t_elst *dirs;
	t_elst *last;

	dirs = NULL;
	last = NULL;
	if (!*entries)
		return (g_dirs ? ft_putchar('\n') : (void)0);
	if (g_long_display)
		handle_long_display(*entries, (*entries)->next != NULL);
	while ((current = elst_pop(entries)))
	{
		g_print(current);
		if (current->type == EDIR && (!g_get_all || !ISDOTDIR(current->name)))
			last = elst_add(&dirs, last, current);
		else
			elst_del(current);
	}
	if (last)
	{
		last->next = g_dirs;
		g_dirs = dirs;
	}
	if (g_dirs)
		ft_putchar('\n');
}
