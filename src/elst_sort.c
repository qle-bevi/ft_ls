/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elst_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 19:17:22 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/09 21:49:04 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		split(t_elst *head, t_elst **a, t_elst **b)
{
	t_elst *fast;
	t_elst *slow;

	if (!head || !head->next)
	{
		*a = head;
		*b = NULL;
		return ;
	}
	slow = head;
	fast = head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

static t_elst	*merge(t_elst *a, t_elst *b, BOOL (*cmp)(t_elst *, t_elst *))
{
	t_elst *result;

	if (!a)
		return (b);
	if (!b)
		return (a);
	if (cmp(a, b))
	{
		result = a;
		result->next = merge(a->next, b, cmp);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next, cmp);
	}
	return (result);
}

void			elst_sort(t_elst **begin, BOOL (*cmp)(t_elst *, t_elst *))
{
	t_elst *head;
	t_elst *a;
	t_elst *b;

	head = *begin;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	elst_sort(&a, cmp);
	elst_sort(&b, cmp);
	*begin = merge(a, b, cmp);
}
