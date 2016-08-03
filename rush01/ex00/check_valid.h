/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 23:59:31 by asun              #+#    #+#             */
/*   Updated: 2016/07/23 23:59:33 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_VALID_H
# define CHECK_VALID_H
# include "initialize.h"

t_pos	***check_input(int argc, char **argv);
int		check_valid(int r, int c, t_pos ***map);

#endif
