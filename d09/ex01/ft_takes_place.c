/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 12:34:49 by asun              #+#    #+#             */
/*   Updated: 2016/07/22 12:34:49 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_time(int hour)
{
	if (hour >= 100)
		hour /= 100;
	if (hour >= 24)
		hour -= 24;
	if (hour < 0)
		hour += 24;
	if (hour < 12)
	{
		if (hour == 0)
			hour = 12;
		printf("%d.00 A.M. ", hour);
	}
	else
	{
		if (hour > 12)
			hour -= 12;
		printf("%d.00 P.M. ", hour);
	}
}

void	ft_takes_place(int hour)
{
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	print_time(hour);
	printf("AND ");
	print_time(hour + 1);
	printf("\n");
}

int main()
{
	ft_takes_place(23);
}
