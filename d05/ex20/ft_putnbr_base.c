/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:34:44 by asun              #+#    #+#             */
/*   Updated: 2016/07/19 11:34:45 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		check_valid_base(char *base)
{
	int l;
	int i;
	int j;

	i = 0;
	l = ft_strlen(base);
	if (l <= 1)
		return (0);
	while (i < l - 1)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] <= 31)
			return (0);
		while (j < l)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	recursive_print(int nbr, char *base, int iter_c)
{
	int		numeric_base;
	long	n;

	if (!check_valid_base(base))
		return ;
	numeric_base = ft_strlen(base);
	n = nbr;
	if (n == 0)
	{
		if (iter_c == 0)
			ft_putchar(base[0]);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	recursive_print(n / numeric_base, base, iter_c + 1);
	ft_putchar(base[n % numeric_base]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	recursive_print(nbr, base, 0);
}
