/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:16:44 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:32:56 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_item;

	new_item = malloc(sizeof(t_list));
	if (!(new_item))
		return (NULL);
	if (content == NULL)
		new_item->content = NULL;
	else
	{
		new_item->content = content;
		new_item->next = NULL;
	}
	return (new_item);
}
