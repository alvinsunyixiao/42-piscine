/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 22:24:32 by asun              #+#    #+#             */
/*   Updated: 2016/07/15 22:24:35 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	write_occupied(int i, int j, int map[][9])
{
	if (i >= 1 && i <= 8 && j >= 1 && j <= 8)
	{
		map[i][j] = 1;
	}
	return ;
}

void	modify_map(int x, int y, int map[][9], int orgin_map[][9])
{
	int i;
	int j;

	i = 1;
	while (i <= 8)
	{
		j = 1;
		while (j <= 8)
		{
			orgin_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	while (i >= 2 || j >= 2)
	{
		write_occupied(i - 1, y, map);
		write_occupied(x, j - 1, map);
		write_occupied(j - y + x - 1, j - 1, map);
		write_occupied(i - 1, y + x - i + 1, map);
		i--;
		j--;
	}
	map[i][j] = 3;
	orgin_map[i][j] = 3;
}

void	initialize(int map[][9])
{
	int i;
	int j;

	i = 1;
	while (i <= 8)
	{
		j = 1;
		while (j <= 8)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		recursive_count(int sum, int col, int map[][9], int actual_pos)
{
	int i;
	int orgin_map[9][9];

	if (col == 9)
	{
		return (sum + 1);
	}
	i = 1;
	while (i <= 8)
	{
		if (map[i][col] == 1)
		{
			i++;
			continue;
		}
		modify_map(i, col, map, orgin_map);
		sum = recursive_count(sum, col + 1, map, actual_pos * 10 + i);
		modify_map(1, 1, orgin_map, map);
		i++;
	}
	return (sum);
}

int		ft_eight_queens_puzzle(void)
{
	int map[9][9];

	initialize(map);
	return (recursive_count(0, 1, map, 0));
}
