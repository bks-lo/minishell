/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:34:58 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/01/10 16:12:41 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ms_free_tokens(t_token *token)
{
	t_token	*next;

	while (token)
	{
		next = token->next;
		free(token->value);
		free(token);
		token = next;
	}
}

t_token_types	catego_toketype(char *content)
{
	if (!content)
		return (T_END);
	if (!ft_strcmp(content, "|"))
		return (T_PIPE);
	else if (!ft_strcmp(content, "<<"))
		return (T_DLESS);
	else if (!ft_strcmp(content, ">>"))
		return (T_DGREAT);
	else if (!ft_strcmp(content, ">"))
		return (T_RED_TO);
	else if (!ft_strcmp(content, "<"))
		return (T_RED_FROM);
	else
		return (T_WORD);
}

void	ft_tokenadd_back(t_token **lst, t_token *new)
{
	t_token	*current;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	current = (*lst);
	while (current->next != 0)
	{
		current = current->next;
	}
	current->next = new;
}

t_token	*ft_newtoken(void *content)
{
	t_token		*re;

	re = (t_token *)malloc(sizeof(t_token));
	if (!re)
		return (0);
	re->value = content;
	re->type = (int)catego_toketype(content);
	re->next = 0;
	return (re);
}

t_token	*ms_tokenizer(char *line)
{
	char	**res;
	int		i;
	t_token	*token;
	t_token	*current;

	token = 0;
	i = 0;
	res = ft_split_qu(line, ' ');
	while (res[i])
	{
		//printf("res[i]:|%s|\n", res[i]);
		current = ft_newtoken(res[i]);
		ft_tokenadd_back(&token, current);
		i++;
	}
	free(res);
	ft_tokenadd_back(&token, ft_newtoken(NULL));
	return (token);
}
