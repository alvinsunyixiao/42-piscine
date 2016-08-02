/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 11:10:09 by asun              #+#    #+#             */
/*   Updated: 2016/07/18 11:10:12 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

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
}
