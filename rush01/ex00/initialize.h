/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 00:00:42 by asun              #+#    #+#             */
/*   Updated: 2016/07/24 00:00:44 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_pos
{
	int value;
	int box_r;
	int box_c;
}				t_pos;
t_pos			*create_obj(char nb, int r, int c);
t_pos			***initialize(int argc, char **argv);

#endif
