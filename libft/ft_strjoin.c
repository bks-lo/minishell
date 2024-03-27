/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:32:46 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:43:28 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		sub_index;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	index = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * index);
	if (!(str))
		return (NULL);
	index = 0;
	sub_index = 0;
	if (s1[0] != '\0')
		while (s1[sub_index] != '\0')
			str[index++] = s1[sub_index++];
	sub_index = 0;
	if (s2[0] != '\0')
		while (s2[sub_index] != '\0')
			str[index++] = s2[sub_index++];
	str[index] = '\0';
	return (str);
}
