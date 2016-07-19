/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:01:51 by asun              #+#    #+#             */
/*   Updated: 2016/07/18 18:01:52 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int str_len;
	int search_len;
	int j;

	i = 0;
	str_len = ft_strlen(str);
	search_len = ft_strlen(to_find);
	if (search_len == 0)
		return (str);
	while (i < str_len - search_len)
	{
		j = i;
		while (j < i + search_len)
		{
			if (j == i + search_len - 1)
				return (str + i);
			if (str[i] != to_find[j - i])
				break ;
			j++;
		}
		i++;
	}
	return (0);
}
