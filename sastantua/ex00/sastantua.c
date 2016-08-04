/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 19:36:09 by asun              #+#    #+#             */
/*   Updated: 2016/07/16 19:36:11 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_space(int last_line_count, int current_line_count)
{
	int i;
	int count;

	i = 0;
	count = last_line_count / 2 + 1 - (current_line_count / 2 + 1);
	while (i < count)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('/');
	return ;
}

int		calculate_last_line(int n)
{
	int i;
	int sum;
	int adder;

	if (n == 1)
		return (7);
	else if (n == 2)
		return (19);
	sum = 17;
	i = 0;
	adder = 6;
	while (i < n - 2)
	{
		adder += (i % 2) + 1;
		sum += adder * 2;
		i++;
	}
	return (sum + 2);
}

void	print_last_section(int ls, int s, int offset, int last_line)
{
	int i;
	int j;
	int ds;

	ds = s - (s + 1) % 2;
	i = 0;
	while (i < ls)
	{
		j = 0;
		s = i + offset / 2;
		print_space(last_line, 2 * i + 3 + offset);
		while (j < 2 * i + 1 + offset)
		{
			if (ls >= 7 && i == ls - ds / 2 - 1 && j == s + (ds / 2) - 1)
				ft_putchar('$');
			else if (j >= s - (ds / 2) && j <= s + (ds / 2) && i >= ls - ds)
				ft_putchar('|');
			else
				ft_putchar('*');
			j++;
		}
		ft_putchar('\\');
		ft_putchar('\n');
		i++;
	}
}

void	print_section(int sec_size, int size, int offset)
{
	int i;
	int j;

	i = 0;
	if (sec_size != 3)
		offset += (sec_size / 2 + 1) * 2;
	if (sec_size >= size + 2)
	{
		print_last_section(sec_size, size, offset, calculate_last_line(size));
		return ;
	}
	while (i < sec_size)
	{
		j = 0;
		print_space(calculate_last_line(size), 2 * i + 3 + offset);
		while (j < 2 * i + 1 + offset)
		{
			ft_putchar('*');
			j++;
		}
		ft_putchar('\\');
		ft_putchar('\n');
		i++;
	}
	print_section(sec_size + 1, size, j - 1);
}

void	sastantua(int size)
{
	int i;

	i = 0;
	print_section(3, size, 0);
}
