/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:09:51 by asun              #+#    #+#             */
/*   Updated: 2016/08/03 12:09:56 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate.h"
#include <stdlib.h>
#include "global.h"

void	set_gar(int m, int row, int col)
{
	if (m > g_max)
	{
		g_max = m;
		g_row = row;
		g_col = col;
	}
}

void	reset_gvar(int *i)
{
	g_row = 0;
	g_col = 0;
	g_max = -1;
	*i = -1;
}

int		min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int		modify(char **map, unsigned int **value, int row)
{
	int i;
	int j;

	i = g_row;
	while (i > g_row - g_max)
	{
		j = g_col;
		while (j > g_col - g_max)
		{
			map[i][j] = g_sym[2];
			j--;
		}
		i--;
	}
	i = 0;
	while (i < row)
	{
		free(value[i]);
		i++;
	}
	free(value);
	return (1);
}

int		calculate(char **map, int row, int col)
{
	unsigned int	**value;
	int				i;
	int				j;

	reset_gvar(&i);
	value = (unsigned int**)malloc(sizeof(unsigned int*) * row);
	while (++i < row)
	{
		j = -1;
		value[i] = (unsigned int*)malloc(sizeof(unsigned int) * col - 1);
		while (++j < col - 1)
		{
			if (map[i][j] != g_sym[0] && map[i][j] != g_sym[1])
				return (0);
			if (i == 0 || j == 0)
				value[i][j] = (map[i][j] == g_sym[0]) ? 1 : 0;
			else
				value[i][j] = (map[i][j] == g_sym[0]) ? min(value[i - 1][j],
					value[i][j - 1], value[i - 1][j - 1]) + 1 : 0;
			set_gar(value[i][j], i, j);
		}
		if (map[i][j] != '\n')
			return (0);
	}
	return (modify(map, value, row));
}
