/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:22:49 by asun              #+#    #+#             */
/*   Updated: 2016/07/27 11:22:49 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_p(void **a, void **b)
{
	void *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		ft_list_size(t_list *begin_list)
{
	t_list	*tmp;
	int		sum;

	if (!begin_list)
		return (0);
	sum = 1;
	tmp = begin_list;
	while (tmp->next)
	{
		sum++;
		tmp = tmp->next;
	}
	return (sum);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		sum;
	int		i;
	int		j;
	t_list	*list;
	t_list	*search;

	sum = ft_list_size(begin_list);
	list = begin_list;
	if (sum == 0 || sum == 1)
		return ;
	i = 0;
	while (i < sum / 2)
	{
		j = i + 1;
		search = list->next;
		while (j++ < sum - i - 1)
			search = search->next;
		swap_p(&(list->data), &(search->data));
		list = list->next;
		i++;
	}
}
