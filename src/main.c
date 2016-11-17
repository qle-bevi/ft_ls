/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:22:05 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 21:31:50 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static BOOL g_output = FALSE;
static BOOL (*g_sort_cmp)(t_elst *, t_elst *) = NULL;
static void (*g_print_entries)(t_elst **) = NULL;
static t_elst *g_entries = NULL;

BOOL g_need_size = FALSE;
BOOL g_long_display = FALSE;
BOOL g_get_all = FALSE;
t_elstinfos g_elstinfos;
t_elst *g_dirs = NULL;

static void	on_illegal_option(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_errexit(USAGE);
}

static void	init(OPTS options)
{
	g_need_size = OPT(options, 'S');
	if (OPT(options, 'S') && OPT(options, 'r'))
		g_sort_cmp = cmp_sizerev;
	else if (OPT(options, 'S'))
		g_sort_cmp = cmp_size;
	else if (OPT(options, 't') && OPT(options, 'r'))
		g_sort_cmp = cmp_timerev;
	else if (OPT(options, 't'))
		g_sort_cmp = cmp_time;
	else if (OPT(options, 'r'))
		g_sort_cmp = cmp_alpharev;
	else
		g_sort_cmp = cmp_alpha;
	g_print_entries =
	OPT(options, 'R') ? print_entries_rec : print_entries_simple;
	if (OPT(options, 'l'))
	{
		g_long_display = TRUE;
		set_print_entry_func(print_entry_long);
	}
	g_get_all = OPT(options, 'a');
}

static void	load_entries(int ac, char **av)
{
	int		i;
	t_elst	*current;
	t_elst	*d_last;
	t_elst	*f_last;

	if (!ac)
		return ((void)elst_add(&g_dirs, NULL, new_entry(ft_strdup("."), TRUE)));
	i = 0;
	d_last = NULL;
	f_last = NULL;
	while (i < ac)
	{
		if ((current = new_entry(ft_strdup(av[i++]), TRUE)))
		{
			if (current->type == EDIR)
				d_last = elst_add(&g_dirs, d_last, current);
			else
				f_last = elst_add(&g_entries, f_last, current);
		}
	}
	elst_sort(&g_dirs, g_sort_cmp);
	elst_sort(&g_entries, g_sort_cmp);
}

static void	do_listing(BOOL all)
{
	t_elst *current;

	if (g_entries)
	{
		g_output = TRUE;
		g_print_entries(&g_entries);
	}
	while ((current = elst_pop(&g_dirs)))
	{
		if (load_dir(current->path, &g_entries, all))
		{
			elst_sort(&g_entries, g_sort_cmp);
			if (g_output)
			{
				ft_putstr(current->path);
				ft_putendl(":");
			}
			g_output = TRUE;
			g_print_entries(&g_entries);
		}
		elst_del(current);
	}
}

int			main(int ac, char **av)
{
	int		i;
	OPTS	options;

	options = 0;
	i = parse_options(ac, av, &options, on_illegal_option);
	init(options);
	load_entries(ac - i, av + i);
	do_listing(OPT(options, 'a'));
	return (EXIT_SUCCESS);
}
