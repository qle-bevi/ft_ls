/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 21:22:28 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 21:22:34 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list **begin)
{
	t_list *new;
	t_list *curr;
	t_list *next;

	if (!begin || !(curr = *begin))
		return (NULL);
	new = NULL;
	while (curr)
	{
		next = curr->next;
		ft_lstadd(&new, curr);
		curr = next;
	}
	return (*begin = new);
}
