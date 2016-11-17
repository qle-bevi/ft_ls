/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 20:20:53 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/10 15:06:29 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

void	print_error(char *str)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(str);
	ft_putchar('\n');
}
