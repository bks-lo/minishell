/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:57:26 by twagner           #+#    #+#             */
/*   Updated: 2021/10/26 11:36:26 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

static t_token_types catego_toketype(char *content)
{
	if (!ft_strcmp(content , "|"))
		return (PIPE);
	else if (!ft_strcmp(content , "&&"))
		return (AND_IF);
	else if (!ft_strcmp(content , "||"))
		return (OR_IF);
	else if (!ft_strcmp(content , "<<"))
		return (DLESS);
	else if (!ft_strcmp(content , ">>"))
		return (DGREAT);
	else if (!ft_strcmp(content , ">"))
		return (RED_TO);
	else if (!ft_strcmp(content , "<"))
		return (RED_FROM);
	else 
		return (WORD);
}

static void	ft_tokenadd_back(t_token **lst, t_token *new)
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

static t_token	*ft_newtoken(void *content)
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
	t_token *token;
	t_token *current;

	token = 0;
	res = ft_split_qu(line, ' ');
	i = -1;
	while(res[++i])
	{
		if(check_special_char(res[i], line))
			return (0);
		current = ft_newtoken(res[i]);
		//res[i] = check_if_envvar(res[i]);
		ft_tokenadd_back(&token, current);
	}
	return (token);
}
