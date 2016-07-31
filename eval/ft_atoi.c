/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 11:16:40 by asun              #+#    #+#             */
/*   Updated: 2016/07/18 11:16:43 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*trim_space(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		str++;
	return (str);
}

int		ft_atoi(char **str)
{
	long	rs;

	rs = 0;
	*str = trim_space(*str);
	while (**str >= '0' && **str <= '9')
	{
		rs *= 10;
		rs += **str - 48;
		(*str)++;
	}
	*str = trim_space(*str);
	return (rs);
}
