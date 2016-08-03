/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 00:02:39 by asun              #+#    #+#             */
/*   Updated: 2016/07/24 00:02:40 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "initialize.h"
# include "check_valid.h"

t_pos	***find_s(int r, int c, t_pos ***map);
void	search(int r, int c, int *rs_c, t_pos ***map);

#endif
