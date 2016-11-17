/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:19:37 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 21:11:53 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_OPTIONS_H
# define PARSE_OPTIONS_H
# include "libft.h"
# define OPTS char
# define VALID_OPTS "alrRSt"
# define OPT(mask, opt) has_option(mask, opt)

int		parse_options(int ac, char **av, OPTS *opts, void (*f)(char c));
BOOL	has_option(OPTS options, char c);
#endif
