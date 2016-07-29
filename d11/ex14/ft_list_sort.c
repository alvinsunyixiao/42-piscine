/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:21:52 by asun              #+#    #+#             */
/*   Updated: 2016/07/27 11:21:53 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	t_list	*search;
	void	*tmpval;

	list = *begin_list;
	if (!list)
		return ;
	while (list->next)
	{
		search = list->next;
		while (search)
		{
			if (cmp(list->data, search->data) > 0)
			{
				tmpval = list->data;
				list->data = search->data;
				search->data = tmpval;
			}
			search = search->next;
		}
		list = list->next;
	}
}
