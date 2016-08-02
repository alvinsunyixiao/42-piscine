/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 20:02:57 by asun              #+#    #+#             */
/*   Updated: 2016/07/31 20:03:06 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*rush00(int x, int y)
{
	int		length;
	t_list	*list;

	list = 0;
	if (x <= 0 || y <= 0)
		return (0);
	length = y;
	while (length >= 1)
	{
		if (length == y)
			ft_list_push_front(&list, ft_putline('o', 'o', '-', x));
		else if (length == 1)
			ft_list_push_front(&list, ft_putline('o', 'o', '-', x));
		else
			ft_list_push_front(&list, ft_putline('|', '|', ' ', x));
		length -= 1;
	}
	return (list);
}
