/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 23:12:49 by asun              #+#    #+#             */
/*   Updated: 2016/07/19 23:12:50 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_num_hexa(int n, int digit)
{
	char *base;

	base = "0123456789abcdef";
	if (digit == 0)
		return ;
	print_num_hexa(n / 16, digit - 1);
	ft_putchar(base[n % 16]);
}

void	print_hexa_str(char *str, unsigned int index, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < 16 && i + index < size)
	{
		print_num_hexa(str[i + index], 2);
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	while (i < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
}

void	printabel(char *str, unsigned int index, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < 16 && i + index < size)
	{
		if (str[i + index] <= 31 || str[i + index] == 127)
			ft_putchar('.');
		else
			ft_putchar(str[i + index]);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*str;
	int				mark;

	if (size == 0)
		return (addr);
	str = addr;
	i = 0;
	if (size % 16 == 0)
		mark = 0;
	else
		mark = 1;
	while (i < size / 16 + mark)
	{
		print_num_hexa(i * 16, 8);
		ft_putchar(':');
		ft_putchar(' ');
		print_hexa_str(str, i * 16, size);
		printabel(str, i * 16, size);
		ft_putchar('\n');
		i++;
	}
	return (addr);
}
