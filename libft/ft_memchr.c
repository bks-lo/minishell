/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:50:37 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:34:04 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, int n)
{
	int				index;
	int				found_c;
	unsigned char	*str_char;
	unsigned char	search_value;

	str_char = (unsigned char *)str;
	search_value = (unsigned char)c;
	index = 0;
	found_c = 0;
	while (index < n && found_c == 0)
	{
		if (str_char[index] == search_value)
			found_c = 1;
		index++;
	}
	if (found_c)
		return ((void *)(str + (index - 1)));
	return (NULL);
}
