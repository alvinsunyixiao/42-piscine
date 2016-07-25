/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 00:55:43 by asun              #+#    #+#             */
/*   Updated: 2016/07/23 00:55:44 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdio.h>

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

t_stock_par			creat_obj(char *str)
{
	int			i;
	int			l;
	char		*cp;
	t_stock_par	rs;

	i = 0;
	l = ft_strlen(str) + 1;
	rs.size_param = l - 1;
	rs.str = str;
	cp = (char*)malloc(sizeof(char) * l);
	while (i < l)
	{
		cp[i] = str[i];
		i++;
	}
	rs.copy = cp;
	rs.tab = ft_split_whitespaces(str);
	return (rs);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*rs;

	rs = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	i = -1;
	creat_obj(av[0]);
	while (++i < ac)
		rs[i] = creat_obj(av[i]);
	rs[i] = creat_obj("");
	rs[i].str = 0;
	return (rs);
}
