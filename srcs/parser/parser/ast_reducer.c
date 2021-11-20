/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_reducer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:31:00 by twagner           #+#    #+#             */
/*   Updated: 2021/11/12 15:06:44 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** AST REDUCER
** The ast reducer simplify the tree by removing all intermediate nodes and
** keeping operators and operands
*/

static t_node	*ms_get_concrete_root(t_node *node)
{
	int		left_reduc;
	int		right_reduc;
	t_node	*new_root;

	left_reduc = 999;
	right_reduc = 999;
	new_root = NULL;
	if (node->left)
		left_reduc = node->left->reduc;
	if (node->right)
		right_reduc = node->right->reduc;
	if (left_reduc <= right_reduc)
	{
		node->left->left = node->right;
		new_root = node->left;
	}
	else
	{
		node->right->left = node->left;
		new_root = node->right;
	}
	free(node);
	return (new_root);
}

static t_node	*ms_get_node(t_node *node, int which)
{
	t_node	*to_promote;
	t_node	*to_child;

	if (node->left)
	{
		to_promote = node->left;
		to_child = node->right;
	}
	if (node->right)
	{
		if (!to_promote || \
			(to_promote && node->right->reduc < to_promote->reduc))
		{
			to_promote = node->right;
			to_child = node->left;
		}
	}
	if (which == TO_PROMOTE)
		return (to_promote);
	return (to_child);
}

static t_node	*ms_promote_child(t_node *node, t_node *parent, int from)
{
	t_node	*to_promsote;
	t_node	*to_child;

	if (parent->left && parent->right)
	{
		to_promote = ms_get_node(node, TO_PROMOTE);
		to_child = ms_get_node(node, TO_CHILD);
		if (!to_promote)
			return (NULL);
		if (from == LEFT)
			parent->left = to_promote;
		else
			parent->right = to_promote;
		if (!to_promote->left)
			to_promote->left = to_child;
		else
			to_promote->right = to_child;
		free(node);
		return (to_promote);
	}
	parent->left = node->left;
	parent->right = node->right;
	free(node);
	return (parent);
}

static void	ms_visit_simplif(t_node *node, t_node *parent, int from)
{
	if (!node)
		return ;
	ms_visit_simplif(node->left, node, LEFT);
	ms_visit_simplif(node->right, node, RIGHT);
	if (node->type == -1)
		node = ms_promote_child(node, parent, from);
	if (node->type == 0)
	{
		if (node->reduc > R_CMD_WORD || node->reduc == -1)
			node->type = A_PARAM;
	}
}

t_node	*ms_simplify_tree(t_node *tree)
{
	while (tree->type == -1)
		tree = ms_get_concrete_root(tree);
	ms_visit_simplif(tree, NULL, ROOT);
	return (tree);
}
