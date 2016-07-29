/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:12:03 by asun              #+#    #+#             */
/*   Updated: 2016/07/27 11:12:03 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *rs;

	rs = begin_list;
	if (!rs)
		return (0);
	while (rs)
	{
		if (!cmp(rs->data, data_ref))
			return (rs);
		rs = rs->next;
	}
	return (0);
}
