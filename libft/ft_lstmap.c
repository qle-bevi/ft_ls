/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:27 by qle-bevi          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:56 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *curr;
	t_list *last;

	if (!lst)
		return (NULL);
	new = NULL;
	while (lst)
	{
		curr = (f) ? f(lst) : ft_lstnew(lst->content, lst->content_size);
		ft_lstpush2((!new) ? &new : &last, curr);
		last = curr;
		lst = lst->next;
	}
	return (new);
}
