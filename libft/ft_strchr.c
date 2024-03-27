/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:28:37 by dscriabi          #+#    #+#             */
/*   Updated: 2020/11/19 14:28:28 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		index;

	index = 0;
	while (str[index] != '\0' || str[index] == c)
	{
		if (str[index] == c)
			return ((char *)(str + index));
		index++;
	}
	return (NULL);
}
