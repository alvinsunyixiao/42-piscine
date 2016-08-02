/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:06:48 by asun              #+#    #+#             */
/*   Updated: 2016/07/30 21:06:49 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include "ft_list.h"

typedef struct	s_style
{
	char		*name;
	t_list		*(*create)(int, int);
}				t_style;

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);

t_list			*rush00(int x, int y);
t_list			*rush01(int x, int y);
t_list			*rush02(int x, int y);
t_list			*rush03(int x, int y);
t_list			*rush04(int x, int y);

#endif
