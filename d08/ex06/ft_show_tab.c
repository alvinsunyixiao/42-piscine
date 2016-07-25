/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 11:18:51 by asun              #+#    #+#             */
/*   Updated: 2016/07/23 11:18:51 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void	print_positive(long nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + 48);
		return ;
	}
	print_positive(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	print_positive(n);
	ft_putchar('\n');
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;
	int j;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size_param);
		j = -1;
		while (par[i].tab[++j])
			ft_putstr(par[i].tab[j]);
		i++;
	}
}
