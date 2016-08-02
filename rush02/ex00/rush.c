/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:21:37 by asun              #+#    #+#             */
/*   Updated: 2016/07/30 21:21:38 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "rush.h"
#include "compare.h"
#include "global.h"

t_list	*ft_read_stdi(int *row, int *column)
{
	char	buffer;
	char	*c;
	t_list	*list;
	t_list	*tmp;

	list = 0;
	while (read(0, &buffer, 1) != 0)
	{
		(*row)++;
		tmp = 0;
		*column = 0;
		while (buffer != '\n')
		{
			c = (char*)malloc(sizeof(char));
			*c = buffer;
			ft_list_push_front(&tmp, c);
			read(0, &buffer, 1);
			(*column)++;
		}
		ft_list_push_front(&list, tmp);
	}
	return (list);
}

int		main(void)
{
	int		row;
	int		column;
	t_list	*list;

	row = 0;
	column = 0;
	list = ft_read_stdi(&row, &column);
	if (!search(list, row, column, g_style))
		ft_putstr("aucune\n");
	return (0);
}
