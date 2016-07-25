/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 21:56:21 by asun              #+#    #+#             */
/*   Updated: 2016/07/20 21:56:23 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	append_c(char c, char **str)
{
	int		i;
	char	*old;
	char	*new;

	old = *str;
	i = 0;
	new = (char*)malloc(sizeof(char) * (ft_strlen(old) + 2));
	new[0] = c;
	while (old[i] != '\0')
	{
		new[i + 1] = old[i];
		i++;
	}
	new[i + 1] = '\0';
	free(*str);
	*str = new;
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int num_base;
	int rs;
	int j;

	i = 0;
	rs = 0;
	num_base = ft_strlen(base);
	while (i < ft_strlen(str))
	{
		rs *= num_base;
		j = 0;
		while (base[j++] != str[i])
			;
		rs += j - 1;
		i++;
	}
	return (rs);
}

void	recursive_print(int nbr, char *base, int iter_c, char **str)
{
	int		numeric_base;
	long	n;

	numeric_base = ft_strlen(base);
	n = nbr;
	if (n == 0)
	{
		if (iter_c == 0)
			append_c(base[0], str);
		return ;
	}
	if (n < 0)
	{
		append_c('-', str);
		n = -n;
	}
	append_c(base[n % numeric_base], str);
	recursive_print(n / numeric_base, base, iter_c + 1, str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		ng_mark;

	ng_mark = 0;
	if (nbr[0] == '-')
	{
		nbr++;
		ng_mark = 1;
	}
	str = (char*)malloc(sizeof(char) * 1);
	str[0] = '\0';
	recursive_print(ft_atoi_base(nbr, base_from), base_to, 0, &str);
	if (ng_mark)
		append_c('-', &str);
	return (str);
}
