/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 09:42:06 by jchoi             #+#    #+#             */
/*   Updated: 2016/07/16 10:43:00 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putline(char start, char end, char fill, int length)
{
	ft_putchar(start);
	while (length > 2)
	{
		ft_putchar(fill);
		length -= 1;
	}
	if (length == 2)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int		length;

	if (x <= 0 || y <= 0)
		return ;
	length = y;
	while (length >= 1)
	{
		if (length == y || length == 1)
		{
			ft_putline('A', 'C', 'B', x);
		}
		else
		{
			ft_putline('B', 'B', ' ', x);
		}
		length -= 1;
	}
}
