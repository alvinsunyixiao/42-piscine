/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:52:25 by asun              #+#    #+#             */
/*   Updated: 2016/07/28 10:52:25 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#define BUF_SIZE 10

void	display_one(int fd, int offset)
{
	char	buf[BUF_SIZE + 1];
	int		ret;

	lseek(fd, -offset, SEEK_END);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (errno == EISDIR)
		{
			errno = 0;
			return ;
		}
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	close(fd);
}

void	display(int fd, char *file_name, int offset)
{
	char	buf[BUF_SIZE + 1];
	int		ret;

	lseek(fd, -offset, SEEK_END);
	ft_putstr("==> ");
	ft_putstr(file_name);
	ft_putstr(" <==\n");
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (errno == EISDIR)
		{
			errno = 0;
			return ;
		}
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	close(fd);
}

void	print(int ac, char **argv)
{
	int		fd;
	int		i;
	int		offset;

	i = 2;
	offset = ft_atoi(argv[2]);
	while (++i < ac)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd != -1)
		{
			if (i != 3)
				ft_putchar('\n');
			if (ac == 4)
				display_one(fd, offset);
			else
				display(fd, argv[i], offset);
		}
		else if (errno == ENOENT)
			throw_bad_fd(argv[i]);
	}
}
