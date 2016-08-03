/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 00:02:22 by asun              #+#    #+#             */
/*   Updated: 2016/07/24 00:02:23 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"
#include "check_valid.h"
#include "solve.h"
#include "display.h"

int	main(int argc, char **argv)
{
	int		i;
	t_pos	***map;

	i = 0;
	map = check_input(argc, argv);
	if (!map)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	search(0, 0, &i, map);
	if (i != 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	map = find_s(0, 0, map);
	display_map(map);
	return (0);
}
