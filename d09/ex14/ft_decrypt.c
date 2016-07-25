/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 16:41:17 by asun              #+#    #+#             */
/*   Updated: 2016/07/22 16:41:18 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_perso.h"

int		ft_atoi(char *str)
{
	int		n_mark;
	int		i;
	long	rs;

	rs = 0;
	i = 0;
	n_mark = 0;
	if (str[i] == '-')
	{
		n_mark = 1;
		i++;
	}
	if (str[0] == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rs *= 10;
		rs += str[i] - 48;
		i++;
	}
	if (n_mark)
		rs = -rs;
	return (rs);
}

int		count_words(char *str)
{
	int rs;
	int i;

	rs = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '|' && str[i] != ';')
			if (str[i] != '\0')
				i++;
			else
				break ;
		while (str[i] == '|' || str[i] == ';')
			i++;
		rs++;
	}
	return (rs);
}

char	*first_str(char *str, int *index)
{
	int		i;
	int		start;
	char	*rs;
	int		end;

	start = *index;
	i = start;
	while (str[i] != '|' && str[i] != ';' && str[i] != '\0')
		i++;
	end = i;
	while (str[i] == '|' || str[i] == ';')
		i++;
	*index = i;
	i = -1;
	rs = (char*)malloc(sizeof(char) * (end - start + 1));
	while (++i < end - start)
		rs[i] = str[start + i];
	rs[i] = '\0';
	return (rs);
}

char	**ft_split_word(char *str, int *w_c)
{
	char	**rs;
	int		i;
	int		index;

	*w_c = count_words(str);
	rs = (char**)malloc(sizeof(char*) * (*w_c + 1));
	i = 0;
	index = 0;
	while (str[i] != '\0')
		rs[index++] = first_str(str, &i);
	rs[index] = 0;
	return (rs);
}

t_perso	**ft_decrypt(char *str)
{
	char	**words;
	int		i;
	int		word_c;
	t_perso	**rs;

	words = ft_split_word(str, &word_c);
	rs = (t_perso**)malloc(sizeof(t_perso*) * (word_c + 1));
	i = 0;
	while (*words)
	{
		rs[i / 2] = (t_perso*)malloc(sizeof(t_perso));
		rs[i / 2]->age = ft_atoi(*words++);
		rs[i / 2]->name = *words++;
		i += 2;
	}
	return (rs);
}
