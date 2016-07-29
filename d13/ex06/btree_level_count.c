/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 14:10:17 by asun              #+#    #+#             */
/*   Updated: 2016/07/29 14:10:17 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	btree_level_count(t_btree *root)
{
	int left_c;
	int right_c;

	if (!root)
		return (0);
	left_c = btree_level_count(root->left);
	right_c = btree_level_count(root->right);
	return (max(left_c, right_c) + 1);
}
