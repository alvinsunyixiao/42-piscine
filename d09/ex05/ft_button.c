/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:07:46 by asun              #+#    #+#             */
/*   Updated: 2016/07/22 13:07:46 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_button(int i, int j, int k)
{
	if (j > i)
		ft_swap(&i, &j);
	if (k > i)
		ft_swap(&i, &k);
	if (k > j)
		ft_swap(&j, &k);
	return (j);
}