/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:35:50 by asun              #+#    #+#             */
/*   Updated: 2016/07/14 15:35:53 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	negative_mark;

	negative_mark = 0;
	i = 0;
	num = 0;
	if (str[0] == '-')
	{
		negative_mark = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	if (negative_mark)
	{
		num = -num;
	}
	return (num);
}
