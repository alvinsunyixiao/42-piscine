/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:49:53 by asun              #+#    #+#             */
/*   Updated: 2016/07/28 10:49:53 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft.h"
#define BUF_SIZE 10

void	display(char *file_name)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		ret;

	fd = open(file_name, O_RDONLY);
	if (fd != -1)
	{
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
	}
	close(fd);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	char	*file_name;

	if (argc < 2)
	{
		ft_puterr("File name missing.\n");
		return (0);
	}
	else if (argc > 2)
	{
		ft_puterr("Too many arguments\n");
		return (0);
	}
	file_name = argv[1];
	display(file_name);
	return (0);
}
