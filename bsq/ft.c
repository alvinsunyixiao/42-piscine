/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:22:17 by asun              #+#    #+#             */
/*   Updated: 2016/08/03 12:22:18 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

t_list	*ft_create(char c)
{
	t_list *list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list)
	{
		list->c = c;
		list->next = NULL;
	}
	return (list);
}

int		ft_read(int fd, char *buf, int length)
{
	int ct;
	int size;

	ct = 0;
	while (length)
	{
		size = read(fd, buf, length);
		ct += size;
		buf += size;
		length -= size;
		if (size == 0 || size == -1)
			break ;
	}
	return (ct);
}
