/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 14:06:56 by asun              #+#    #+#             */
/*   Updated: 2016/07/29 14:06:56 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root,
	void *item, int (*cmpf)(void *, void *))
{
	t_btree *tmp;

	tmp = *root;
	if (!tmp)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, tmp->item) < 0)
	{
		if (!(tmp->left))
			tmp->left = btree_create_node(item);
		else
			btree_insert_data(&(tmp->left), item, cmpf);
	}
	else
	{
		if (!(tmp->right))
			tmp->right = btree_create_node(item);
		else
			btree_insert_data(&(tmp->right), item, cmpf);
	}
}
