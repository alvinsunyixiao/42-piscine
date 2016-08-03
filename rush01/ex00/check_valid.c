/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 23:59:25 by asun              #+#    #+#             */
/*   Updated: 2016/07/23 23:59:25 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_valid.h"

int		check_arg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '1' && str[i] <= '9') || str[i] == '.'))
			return (0);
		i++;
	}
	if (i != 9)
		return (0);
	return (1);
}

int		check_valid(int r, int c, t_pos ***map)
{
	int i;
	int j;
	int box_r;
	int box_c;

	i = -1;
	while (++i < 9)
		if ((map[r][i]->value == map[r][c]->value && i != c) ||
			(map[i][c]->value == map[r][c]->value && i != r))
			return (0);
	i = -1;
	box_r = map[r][c]->box_r * 3;
	box_c = map[r][c]->box_c * 3;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (map[box_r + i][box_c + j]->value == map[r][c]->value &&
				box_r + i != r && box_c + j != c)
				return (0);
	}
	return (1);
}

t_pos	***scan_map(t_pos ***map)
{
	int i;
	int j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
			if (map[i][j]->value != 0 && !(check_valid(i, j, map)))
				return (0);
	}
	return (map);
}

t_pos	***check_input(int argc, char **argv)
{
	int		i;
	t_pos	***map;

	i = 1;
	if (argc != 10)
		return (0);
	while (i < 10)
	{
		if (!check_arg(argv[i]))
			return (0);
		i++;
	}
	map = initialize(argc, argv);
	return (scan_map(map));
}
