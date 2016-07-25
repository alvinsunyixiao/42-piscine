/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 01:33:54 by asun              #+#    #+#             */
/*   Updated: 2016/07/22 01:33:55 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		noncasecmp(char c1, char c2)
{
	if (c1 == c2 || c1 == c2 + 'a' - 'A' || c1 == c2 + 'A' - 'a')
		return (1);
	else
		return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ss(char *str, char *to_find)
{
	int i;
	int str_len;
	int search_len;
	int j;

	i = 0;
	str_len = ft_strlen(str);
	search_len = ft_strlen(to_find);
	if (search_len == 0)
		return (0);
	while (i < str_len - search_len + 1)
	{
		j = 0;
		while (j < search_len)
		{
			if (!noncasecmp(str[i + j], to_find[j]))
				break ;
			if (j == search_len - 1)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int		check(char *str, char *to_find)
{
	int start;
	int end;
	int i;

	i = 0;
	if (ss(str, to_find) == -1)
		return (0);
	start = ss(str, to_find);
	end = start + ft_strlen(to_find);
	while (str[i] != '\0')
	{
		if (i >= start && i < end)
		{
			i++;
			continue ;
		}
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	*w1;
	char	*w2;
	char	*w3;
	int		i;

	i = 1;
	w1 = "president";
	w2 = "attack";
	w3 = "Powers";
	while (i < argc)
	{
		if (check(argv[i], w1) || check(argv[i], w2) || check(argv[i], w3))
		{
			write(1, "Alert!!!\n", 9);
			break ;
		}
		i++;
	}
	return (0);
}
