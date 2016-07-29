/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:32:24 by asun              #+#    #+#             */
/*   Updated: 2016/07/27 11:32:25 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *last;

	last = *begin_list;
	if (!last)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = ft_create_elem(data);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *tmp;

	tmp = ft_create_elem(data);
	tmp->next = *begin_list;
	*begin_list = tmp;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *list;
	t_list *obj;

	list = *begin_list;
	if (!(obj = ft_create_elem(data)))
		return ;
	if (cmp(data, list->data) < 0)
	{
		ft_list_push_front(begin_list, data);
		return ;
	}
	while (list->next)
	{
		if (cmp(data, list->next->data) < 0)
		{
			ft_list_push_front(&(list->next), data);
			return ;
		}
		list = list->next;
	}
	ft_list_push_back(begin_list, data);
}
