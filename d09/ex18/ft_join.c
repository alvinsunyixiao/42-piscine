/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:33:04 by asun              #+#    #+#             */
/*   Updated: 2016/07/22 13:33:05 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		count_char(char **tab, char *sep)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (tab[i])
	{
		sum += ft_strlen(tab[i]);
		sum += ft_strlen(sep);
		i++;
	}
	return (sum);
}

char	*ft_strcat(char *dest, char *src)
{
	int l;
	int i;

	l = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i + l] = src[i];
		i++;
	}
	dest[i + l] = '\0';
	return (dest);
}

char	*ft_join(char **tab, char *sep)
{
	int		c_c;
	char	*rs;
	int		i;
	int		index;

	c_c = count_char(tab, sep);
	rs = (char*)malloc(sizeof(char) * (c_c + 1));
	rs[0] = '\0';
	i = 0;
	index = 0;
	while (tab[i])
	{
		ft_strcat(rs, tab[i]);
		ft_strcat(rs, sep);
		i++;
	}
	rs[c_c - ft_strlen(sep)] = '\0';
	return (rs);
}
