/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:50:00 by dscriabi          #+#    #+#             */
/*   Updated: 2020/11/19 13:15:11 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		index;
	int		length;

	length = ft_strlen(str);
	index = length;
	while (index >= 0 || str[index] == c)
	{
		if (str[index] == c)
			return ((char *)(str + index));
		index--;
	}
	return (NULL);
}
