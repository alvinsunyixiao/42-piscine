/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:51:19 by asun              #+#    #+#             */
/*   Updated: 2016/07/28 10:51:20 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft.h"
#include "errno.h"
#define BUF_SIZE 10

void	throw_dir_err(char *dir)
{
	ft_puterr("cat: ");
	ft_puterr(dir);
	ft_puterr(": Is a directory\n");
}

void	throw_bad_fd(char *file_name)
{
	ft_puterr("cat: ");
	ft_puterr(file_name);
	ft_puterr(": No such file or directory\n");
}

void	display(int fd, char *file_name)
{
	char	buf[BUF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (errno == EISDIR)
		{
			throw_dir_err(file_name);
			errno = 0;
			return ;
		}
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc == 1)
	{
		fd = 0;
		display(fd, 0);
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (errno == ENOENT)
		{
			throw_bad_fd(argv[i]);
			errno = 0;
			continue;
		}
		display(fd, argv[i]);
		close(fd);
	}
	return (0);
}
