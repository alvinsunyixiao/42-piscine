/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:10:58 by asun              #+#    #+#             */
/*   Updated: 2016/08/03 12:10:59 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "calculate.h"
#include <unistd.h>
#include <fcntl.h>
#include "global.h"

void	process_one(int fd)
{
	char	**a;
	int		row;
	int		col;
	int		i;

	a = arman_read(&row, &col, fd);
	if (!a ||
		g_sym[0] == g_sym[1] || g_sym[0] == g_sym[2] || g_sym[1] == g_sym[2])
	{
		write(1, "map error\n", 10);
		return ;
	}
	if (!calculate(a, row, col))
	{
		write(1, "map error\n", 10);
		return ;
	}
	i = -1;
	while (++i < row)
		write(1, a[i], col);
}

int		main(int argc, char **argv)
{
	int i;
	int fd;

	i = 0;
	if (argc == 1)
	{
		process_one(0);
		return (0);
	}
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(1, "map error\n", 10);
			continue;
		}
		process_one(fd);
		close(fd);
	}
	return (0);
}
