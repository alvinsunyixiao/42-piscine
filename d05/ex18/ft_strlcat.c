/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 23:44:22 by asun              #+#    #+#             */
/*   Updated: 2016/07/18 23:44:23 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long			ft_strlen(char *str)
{
	long i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	long dl;
	long i;
	long sl;
	long s;

	s = size;
	i = 0;
	dl = ft_strlen(dest);
	sl = ft_strlen(src);
	while ((i < size - dl - 1) && i < sl)
	{
		dest[i + dl] = src[i];
		i++;
	}
	if (size - dl - 1 > 0)
		dest[i + dl] = '\0';
	if (s < dl)
		return (s + sl);
	else
		return (dl + sl);
}
