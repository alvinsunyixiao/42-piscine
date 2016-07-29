/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:02:52 by asun              #+#    #+#             */
/*   Updated: 2016/07/27 11:02:53 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*rs;

	i = 1;
	if (!begin_list || !nbr)
		return (0);
	rs = begin_list;
	while (rs->next && i < nbr)
	{
		rs = rs->next;
		i++;
	}
	if (i != nbr)
		return (0);
	return (rs);
}
