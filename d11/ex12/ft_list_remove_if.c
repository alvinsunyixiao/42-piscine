/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:15:47 by asun              #+#    #+#             */
/*   Updated: 2016/07/27 11:15:47 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	remove_following(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *begin_list;
	if (!tmp)
		return ;
	while (tmp)
	{
		while (!cmp(tmp->next->data, data_ref))
		{
			tmp2 = tmp->next->next;
			free(tmp->next);
			tmp->next = tmp2;
			if (!tmp2)
				break ;
		}
		tmp = tmp->next;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;

	tmp = *begin_list;
	if (!tmp)
		return ;
	while (tmp && !cmp(tmp->data, data_ref))
	{
		*begin_list = tmp->next;
		free(tmp);
		tmp = *begin_list;
	}
	remove_following(begin_list, data_ref, cmp);
}
