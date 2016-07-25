/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:31:37 by asun              #+#    #+#             */
/*   Updated: 2016/07/22 13:31:39 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	recurrsion(int value, int digit)
{
	if (digit == 0)
		return (0);
	return (recurrsion(value / 2, digit - 1) + (value % 2));
}

unsigned int	ft_active_bits(int value)
{
	return (recurrsion(value, 32));
}
