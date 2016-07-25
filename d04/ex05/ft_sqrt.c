/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 12:02:51 by asun              #+#    #+#             */
/*   Updated: 2016/07/15 12:02:52 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	square(int nb)
{
	return (nb * nb);
}

int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		return (0);
	}
	while (square(i) <= nb)
	{
		if (square(i) == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
