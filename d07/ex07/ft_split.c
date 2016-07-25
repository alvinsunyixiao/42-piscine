/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 15:17:16 by asun              #+#    #+#             */
/*   Updated: 2016/07/21 15:17:17 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_seperator(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int rs;
	int i;

	rs = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (!check_seperator(str[i], charset))
			if (str[i] != '\0')
				i++;
			else
				break ;
		while (check_seperator(str[i], charset))
			i++;
		rs++;
	}
	return (rs);
}

char	*first_str(char *str, int *index, char *charset)
{
	int		i;
	int		start;
	char	*rs;
	int		end;

	start = *index;
	i = start;
	while (!(check_seperator(str[i], charset)))
		i++;
	end = i;
	while (check_seperator(str[i], charset))
		i++;
	*index = i;
	i = -1;
	rs = (char*)malloc(end - start + 1);
	while (++i < end - start)
		rs[i] = str[start + i];
	rs[i] = '\0';
	return (rs);
}

char	**ft_split(char *str, char *charset)
{
	char	**rs;
	int		i;
	int		word_c;
	int		index;

	word_c = count_words(str, charset);
	rs = (char**)malloc(sizeof(char*) * (word_c + 1));
	i = 0;
	index = 0;
	while (check_seperator(str[i], charset))
		str++;
	while (str[i] != '\0')
		rs[index++] = first_str(str, &i, charset);
	rs[index] = 0;
	return (rs);
}
