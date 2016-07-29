/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 14:08:01 by asun              #+#    #+#             */
/*   Updated: 2016/07/29 14:08:02 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	t_btree	*rs;

	if (!root)
		return (0);
	if ((rs = btree_search_item(root->left, data_ref, cmpf)))
		return (rs);
	if (!(cmpf(root->item, data_ref)))
		return (root);
	if ((rs = btree_search_item(root->right, data_ref, cmpf)))
		return (rs);
	return (0);
}
