/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:27 by qle-bevi          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:56 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	if (!(ret = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	ret->next = NULL;
	if (!content)
	{
		ret->content = NULL;
		ret->content_size = 0;
		return (ret);
	}
	ret->content_size = content_size;
	ret->content = ft_memalloc(content_size);
	if (!ret->content)
		ret->content = NULL;
	else
		ret->content = ft_memcpy(ret->content, content, content_size);
	return (ret);
}
