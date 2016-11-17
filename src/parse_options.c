/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:32:40 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 19:59:16 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse_options.h"

static OPTS	get_option_value(char flag)
{
	static char valid_options[] = VALID_OPTS;
	int			i;
	char		vo;

	i = 0;
	while ((vo = valid_options[i]))
	{
		if (vo == flag)
			return (1 << i);
		i++;
	}
	return (0);
}

int			parse_options(int ac, char **av, OPTS *options, void (*f)(char c))
{
	int		i;
	char	*curr;
	OPTS	optv;

	i = 0;
	curr = NULL;
	while (++i < ac && av[i][0] == '-')
	{
		curr = av[i];
		if (ft_strequ(curr, "--"))
			return (i + 1);
		while (*(++curr))
		{
			if (!(optv = get_option_value(*curr)))
				if (f)
					f(*curr);
			if (!(*options & optv))
				*options += optv;
		}
	}
	return (i);
}

BOOL		has_option(OPTS options, char c)
{
	return ((options & get_option_value(c)) > 0);
}
