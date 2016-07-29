/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 10:56:09 by asun              #+#    #+#             */
/*   Updated: 2016/07/27 10:56:10 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
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
