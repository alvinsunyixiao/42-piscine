/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 20:24:03 by asun              #+#    #+#             */
/*   Updated: 2016/07/18 20:24:05 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!check_numeric(str[i]))
			return (0);
		i++;
	}
	return (1);
}
