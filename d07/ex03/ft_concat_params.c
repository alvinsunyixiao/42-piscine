/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:17:53 by asun              #+#    #+#             */
/*   Updated: 2016/07/20 14:17:54 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*rs;
	int		i;
	int		j;
	int		l;
	int		k;

	i = -1;
	l = 0;
	k = 0;
	while (++i < argc)
		l += ft_strlen(argv[i]) + 1;
	rs = (char*)malloc(sizeof(char) * l);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (++j < ft_strlen(argv[i]))
			rs[j + k] = argv[i][j];
		rs[j + k] = '\n';
		k += j + 1;
	}
	rs[k - 1] = '\0';
	return (rs);
}
