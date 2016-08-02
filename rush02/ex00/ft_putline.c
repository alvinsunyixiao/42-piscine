/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:21:30 by asun              #+#    #+#             */
/*   Updated: 2016/07/30 21:21:31 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_putline(char start, char end, char fill, int length)
{
	t_list	*list;
	char	*a;
	char	*b;
	char	*c;

	a = (char*)malloc(sizeof(char));
	b = (char*)malloc(sizeof(char));
	c = (char*)malloc(sizeof(char));
	*a = start;
	*b = end;
	*c = fill;
	list = 0;
	ft_list_push_front(&list, a);
	while (length > 2)
	{
		ft_list_push_front(&list, c);
		length -= 1;
	}
	if (length == 2)
		ft_list_push_front(&list, b);
	return (list);
}
