/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:30:22 by asun              #+#    #+#             */
/*   Updated: 2016/07/18 19:30:23 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	min_strlen(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (n > i + 1)
		return (i + 1);
	else
		return (n);
}

int				ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int l;
	unsigned int i;

	l = min_strlen(s1, s2, n);
	i = 0;
	while (i < l)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
