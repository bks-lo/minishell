/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:42:45 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:44:37 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int		index;
	int		s_index;

	index = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	while (big[index] != '\0' && index < len)
	{
		s_index = 0;
		while (little[s_index] == big[index + s_index] && index + s_index < len)
		{
			if (little[s_index + 1] == '\0')
			{
				return ((char *)big + index);
			}
			s_index++;
		}
		index++;
	}
	return (NULL);
}
