/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 17:24:48 by asun              #+#    #+#             */
/*   Updated: 2016/07/20 17:24:50 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i++])
		ft_putchar(str[i - 1]);
}

void	ft_print_words_tables(char **tab)
{
	int i;

	i = 0;
	while (tab[i++])
	{
		ft_putstr(tab[i - 1]);
		ft_putchar('\n');
	}
}
