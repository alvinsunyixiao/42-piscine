/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 17:06:55 by asun              #+#    #+#             */
/*   Updated: 2016/07/20 17:06:56 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *array;

	i = min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	array = (int*)malloc(sizeof(int) * (max - min));
	while (i < max)
	{
		array[i - min] = i;
		i++;
	}
	*range = array;
	return (max - min);
}
