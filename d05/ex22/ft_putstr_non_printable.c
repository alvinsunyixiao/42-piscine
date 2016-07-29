/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 13:41:50 by asun              #+#    #+#             */
/*   Updated: 2016/07/19 13:41:51 by asun             ###   ########.fr       */
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

void	ft_putnbr_base(int nbr, int count)
{
	int		numeric_base;
	long	n;
	char	*base;

	base = "0123456789abcdef";
	numeric_base = ft_strlen(base);
	n = nbr;
	if (n == 0 && count == 1)
	{
		ft_putchar('0');
		return ;
	}
	else if (n == 0)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ft_putnbr_base(n / numeric_base, count + 1);
	ft_putchar(base[n % numeric_base]);
}

int		is_printable(char c)
{
	if (c < 32 || c == 127)
		return (0);
	else
		return (1);
}

void	print_one(char c)
{
	if (is_printable(c))
		ft_putchar(c);
	else
	{
		ft_putchar('\\');
		ft_putnbr_base(c, 0);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		print_one(str[i]);
		i++;
	}
}
