/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 14:03:01 by asun              #+#    #+#             */
/*   Updated: 2016/07/29 14:03:01 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*rs;

	rs = (t_btree*)malloc(sizeof(t_btree));
	rs->item = item;
	rs->left = 0;
	rs->right = 0;
	return (rs);
}
