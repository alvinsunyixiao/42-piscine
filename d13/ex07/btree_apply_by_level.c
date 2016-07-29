/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 14:11:55 by asun              #+#    #+#             */
/*   Updated: 2016/07/29 14:11:56 by asun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int		btree_level_count(t_btree *root)
{
	int left_c;
	int right_c;
	int max;

	if (!root)
		return (0);
	left_c = btree_level_count(root->left);
	right_c = btree_level_count(root->right);
	if (left_c > right_c)
		max = left_c;
	else
		max = right_c;
	return (max + 1);
}

t_list	*ft_create_elem(void *data, int depth)
{
	t_list *tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (0);
	tmp->item = data;
	tmp->next = NULL;
	tmp->depth = depth;
	return (tmp);
}

void	ft_list_push_back(t_list **begin_list, void *data, int depth)
{
	t_list *last;

	last = *begin_list;
	if (!last)
	{
		*begin_list = ft_create_elem(data, depth);
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = ft_create_elem(data, depth);
}

void	process(t_list *list,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list	*tmp;
	int		fe_mark;
	t_btree	*tree;

	fe_mark = 1;
	while (list)
	{
		tree = (t_btree*)(list->item);
		if (tree->left)
			ft_list_push_back(&list, tree->left, list->depth + 1);
		if (tree->right)
			ft_list_push_back(&list, tree->right, list->depth + 1);
		applyf(tree->item, list->depth, fe_mark);
		tmp = list->next;
		if (tmp)
		{
			fe_mark = 0;
			if (list->depth != tmp->depth)
				fe_mark = 1;
		}
		free(list);
		list = tmp;
	}
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list *list;

	if (!root)
		return ;
	list = (t_list*)malloc(sizeof(t_list));
	list->item = root;
	list->depth = 0;
	process(list, applyf);
}
