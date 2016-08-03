/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 00:02:33 by asun              #+#    #+#             */
/*   Updated: 2016/07/24 00:02:34 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

void	destroy(t_pos ***map)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			free(map[i][j]);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}

t_pos	***copy_map(t_pos ***map)
{
	int		i;
	int		j;
	t_pos	***rs;
	t_pos	**temp;
	t_pos	*obj;

	rs = (t_pos***)malloc(sizeof(t_pos**) * 9);
	i = 0;
	while (i < 9)
	{
		j = 0;
		temp = (t_pos**)malloc(sizeof(t_pos*) * 9);
		while (j < 9)
		{
			obj = (t_pos*)malloc(sizeof(t_pos));
			*obj = *(map[i][j]);
			temp[j] = obj;
			j++;
		}
		rs[i] = temp;
		i++;
	}
	return (rs);
}

t_pos	***find_s(int r, int c, t_pos ***map)
{
	int		i;
	t_pos	***rs;
	t_pos	***map_cp;

	map_cp = copy_map(map);
	i = 0;
	rs = 0;
	if (r == 9)
		return (map);
	if (map[r][c]->value != 0)
	{
		if ((rs = find_s(r + (c + 1) / 9, (c + 1) % 9, map_cp)))
			return (rs);
	}
	else
		while (++i <= 9)
		{
			map[r][c]->value = i;
			map_cp = copy_map(map);
			if (check_valid(r, c, map))
				if ((rs = find_s(r + (c + 1) / 9, (c + 1) % 9, map_cp)))
					return (rs);
			destroy(map_cp);
		}
	return (0);
}

void	search(int r, int c, int *rs_c, t_pos ***map)
{
	int		i;
	t_pos	***map_cp;

	if (*rs_c == 2)
		return ;
	map_cp = copy_map(map);
	i = 0;
	if (r == 9)
	{
		(*rs_c) += 1;
		return ;
	}
	if (map[r][c]->value != 0)
		search(r + (c + 1) / 9, (c + 1) % 9, rs_c, map_cp);
	else
		while (++i <= 9)
		{
			map[r][c]->value = i;
			map_cp = copy_map(map);
			if (check_valid(r, c, map))
				search(r + (c + 1) / 9, (c + 1) % 9, rs_c, map_cp);
			destroy(map_cp);
		}
	return ;
}
