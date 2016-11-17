/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:27 by qle-bevi          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:56 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list **begin, void const *content, size_t content_size)
{
	t_list *new;
	t_list *curr;

	if (!begin || !(new = ft_lstnew(content, content_size)))
		return (NULL);
	if (!(curr = *begin))
		return (*begin = new);
	while (curr->next)
		curr = curr->next;
	return (curr->next = new);
}

t_list	*ft_lstpush2(t_list **begin, t_list *new)
{
	t_list *curr;

	if (!(curr = *begin))
		return (*begin = new);
	while (curr->next)
		curr = curr->next;
	return (curr->next = new);
}
