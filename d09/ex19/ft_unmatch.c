/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:33:24 by asun              #+#    #+#             */
/*   Updated: 2016/07/22 13:33:25 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_odd(int *tab, int length, int nb)
{
	int sum;
	int i;

	sum = 0;
	i = 0;
	while (i < length)
	{
		if (tab[i] == nb)
			sum++;
		i++;
	}
	return (sum % 2);
}

int		ft_unmatch(int *tab, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (check_odd(tab, length, tab[i]))
			return (i);
		i++;
	}
	return (0);
}
