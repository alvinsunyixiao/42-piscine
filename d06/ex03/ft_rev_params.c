/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 15:39:37 by asun              #+#    #+#             */
/*   Updated: 2016/07/19 15:39:38 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
	return ;
}

int		main(int argc, char **argv)
{
	int i;

	i = argc - 1;
	while (i >= 1)
	{
		ft_putstr(argv[i]);
		i--;
	}
	return (0);
}
