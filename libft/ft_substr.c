/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:37:38 by dscriabi          #+#    #+#             */
/*   Updated: 2020/11/24 19:52:33 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	index;
	unsigned int	sub_index;
	char			*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	index = 0;
	sub_index = 0;
	while (s[index])
	{
		if (index >= start && sub_index < len)
		{
			str[sub_index] = s[index];
			sub_index++;
		}
		index++;
	}
	str[sub_index] = 0;
	return (str);
}
