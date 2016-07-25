/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 17:06:09 by asun              #+#    #+#             */
/*   Updated: 2016/07/20 17:06:10 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i + 1);
}

char	*ft_strdup(char *src)
{
	char	*rs;
	int		l;
	int		i;

	i = 0;
	l = ft_strlen(src);
	rs = (char*)malloc(sizeof(char) * l);
	if (rs == 0)
		return (rs);
	while (i < l - 1)
	{
		rs[i] = src[i];
		i++;
	}
	rs[i] = '\0';
	return (rs);
}
