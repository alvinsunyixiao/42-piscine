/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 14:14:32 by asun              #+#    #+#             */
/*   Updated: 2016/07/14 14:14:34 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int sum;

	sum = 0;
	while (str[sum] != '\0')
	{
		sum++;
	}
	return (sum);
}

char*ft_strrev(char *str)
{
	int		length;
	int		i;
	char	tempc;

	length = ft_strlen(str) - 1;
	i = 0;
	while (i <= length / 2)
	{
		*tempc = str[i];
		str[i] = str[length - i];
		str[length - i] = *tempc;
		i++;
	}
	return (str);
}
