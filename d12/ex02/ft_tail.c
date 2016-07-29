/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:52:37 by asun              #+#    #+#             */
/*   Updated: 2016/07/28 10:52:38 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft.h"
#include <errno.h>
#include "error.h"
#include "display.h"
#define BUF_SIZE 10

int		main(int argc, char **argv)
{
	if (argc <= 3)
		return (0);
	print(argc, argv);
	return (0);
}
