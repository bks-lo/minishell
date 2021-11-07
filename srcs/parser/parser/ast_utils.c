/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:54:53 by twagner           #+#    #+#             */
/*   Updated: 2021/11/07 10:29:31 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ms_visit_ast(t_node *node)
{
	if (!node)
		return ;
	ms_visit_ast(node->left);
	ms_visit_ast(node->right);
	printf("TYPE : %i, REDUC : %i, DATA : %s\n", node->type, node->reduc, node->data);
}

void	ms_free_tree(t_node	*node)
{
	if (node)
	{
		if (node->left)
			ms_free_tree(node->left);
		if (node->right)
			ms_free_tree(node->right);
		if (!node->left && !node->right)
		{
			free(node->data);
			free(node);
		}
	}
}

t_node	*ms_create_node(void *data, int type, int reduc)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->type = type;
	new->reduc = reduc;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
