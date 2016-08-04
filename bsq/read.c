/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 13:41:39 by aheraldo          #+#    #+#             */
/*   Updated: 2016/08/01 13:41:40 by aheraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "read.h"
#include "global.h"
#include "ft_list.h"

int		create_arr(char **str, int row, int col, int fd)
{
	int		i;
	int		i2;
	char	tmp;

	if (row == 1)
		return (1);
	i = 1;
	str[i] = (char*)malloc(sizeof(char) * (col + 1));
	while ((i2 = ft_read(fd, str[i], col)) && i < row)
	{
		if (str[i][i2 - 1] != '\n')
			return (0);
		i++;
		if (i != row)
			str[i] = (char*)malloc(sizeof(char) * (col + 1));
	}
	if (i == row && !(read(fd, &tmp, 1)))
		return (1);
	else
		return (0);
}

int		count_row(t_list **list, int p)
{
	int num;
	int next;

	num = 0;
	if (*list == NULL)
		return (0);
	if ((*list)->c > '9' && (*list)->c < '0')
		return (-1);
	num = ((*list)->c - '0') * (p);
	*list = (*list)->next;
	next = count_row(list, p * 10);
	if (next != -1)
		num += next;
	else
		num = -1;
	return (num);
}

int		ft_tostring(t_list **list, char *fs, int len)
{
	int		flag;
	t_list	*tmp;

	flag = 0;
	fs[len] = '\0';
	while (*list && flag < 1)
	{
		fs[len - 1] = (*list)->c;
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
		len--;
		if ((*list)->c == '\n')
			flag++;
	}
	flag = 3;
	while (flag > 0)
	{
		if (!(*list))
			return (0);
		if ((*list)->c != '\n')
			g_sym[--flag] = (*list)->c;
		*list = (*list)->next;
	}
	return (1);
}

int		count_col(t_list **list, int fd)
{
	char	s;
	int		col;
	int		flag;
	int		ret;
	t_list	*tmp;

	flag = 0;
	col = 0;
	while ((ret = read(fd, &s, 1)) && flag < 2)
	{
		if (ret == -1)
			return (1);
		if (flag == 1)
			col++;
		tmp = ft_create(s);
		tmp->next = *list;
		*list = tmp;
		if (s == '\n')
			flag++;
		if (flag == 2)
			break ;
	}
	if (flag < 2)
		return (1);
	return (col);
}

char	**arman_read(int *row, int *col, int fd)
{
	t_list	*list;
	char	*fs;
	char	**tab;
	int		i;

	list = 0;
	i = -1;
	*col = count_col(&list, fd);
	if (*col == 1)
		return (0);
	fs = (char*)malloc(sizeof(char) * (*col + 1));
	if (!ft_tostring(&list, fs, *col))
		return (0);
	*row = count_row(&list, 1);
	if (*row < 1)
		return (0);
	tab = (char**)malloc(sizeof(char*) * *row);
	tab[0] = (char*)malloc(sizeof(char) * *col + 1);
	while (fs[++i])
		tab[0][i] = fs[i];
	tab[0][i] = '\0';
	if (!create_arr(tab, *row, *col, fd))
		return (0);
	return (tab);
}
