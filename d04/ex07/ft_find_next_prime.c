/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:22:09 by asun              #+#    #+#             */
/*   Updated: 2016/07/15 13:22:11 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;
	int mark;

	if (nb <= 1)
	{
		return (0);
	}
	else
	{
		i = 1;
		mark = 1;
		while (i <= nb / 2)
		{
			if (nb % i == 0 && !(i == 1))
			{
				mark = 0;
				break ;
			}
			i++;
		}
	}
	return (mark);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
	{
		return (nb);
	}
	else
	{
		return (ft_find_next_prime(nb + 1));
	}
}
