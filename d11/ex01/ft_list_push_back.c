/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 10:51:19 by asun              #+#    #+#             */
/*   Updated: 2016/07/27 10:51:20 by asun             ###   ########.fr       */
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
