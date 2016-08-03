/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 00:02:08 by asun              #+#    #+#             */
/*   Updated: 2016/07/24 00:02:09 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	display_map(t_pos ***map)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(map[i][j]->value + '0');
			if (j != 8)
				ft_putchar(' ');
			else
				ft_putchar('\n');
			j++;
		}
		i++;
	}
}
