/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 00:22:27 by asun              #+#    #+#             */
/*   Updated: 2016/07/22 00:22:29 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	while (factory)
	{
		while (factory[0])
		{
			while (factory[0][0])
			{
				free(factory[0][0]);
				factory[0][0]++;
			}
			free(factory[0]);
			factory[0]++;
		}
		free(factory);
		factory++;
	}
}
