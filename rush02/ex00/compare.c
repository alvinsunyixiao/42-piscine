/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:22:36 by asun              #+#    #+#             */
/*   Updated: 2016/07/30 21:22:36 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compare.h"

int		compare_list(t_list *list1, t_list *list2)
{
	char	*c1;
	char	*c2;

	while (list1 && list2)
	{
		c1 = (char*)list1->data;
		c2 = (char*)list2->data;
		if (*c1 != *c2)
			return (0);
		list1 = list1->next;
		list2 = list2->next;
	}
	if (list1 || list2)
		return (0);
	return (1);
}

int		compare_2d_list(t_list *list1, t_list *list2)
{
	t_list	*tmp1;
	t_list	*tmp2;

	while (list1 && list2)
	{
		tmp1 = (t_list*)list1->data;
		tmp2 = (t_list*)list2->data;
		if (!compare_list(tmp1, tmp2))
			return (0);
		list1 = list1->next;
		list2 = list2->next;
	}
	if (list1 || list2)
		return (0);
	return (1);
}

void	print_rs(char *str, int col, int row)
{
	ft_putchar('[');
	ft_putstr(str);
	ft_putstr("] [");
	ft_putnbr(col);
	ft_putstr("] [");
	ft_putnbr(row);
	ft_putchar(']');
}

int		search(t_list *list, int row, int col, t_style *tab)
{
	int		i;
	t_list	*tmp;
	int		print_mark;

	i = 0;
	print_mark = 0;
	if (!row || !col)
		return (0);
	while (i < 5)
	{
		tmp = tab[i].create(col, row);
		if (compare_2d_list(tmp, list))
		{
			if (print_mark)
				ft_putstr(" || ");
			print_rs(tab[i].name, col, row);
			print_mark = 1;
		}
		i++;
	}
	if (print_mark)
		ft_putchar('\n');
	return (print_mark);
}
