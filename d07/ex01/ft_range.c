/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 17:06:38 by asun              #+#    #+#             */
/*   Updated: 2016/07/20 17:06:39 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *rs;

	if (min >= max)
		return (0);
	rs = (int*)malloc(sizeof(int) * (max - min));
	i = min;
	while (i < max)
	{
		rs[i - min] = i;
		i++;
	}
	return (rs);
}
