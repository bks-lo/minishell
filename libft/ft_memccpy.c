/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:47:55 by dscriabi          #+#    #+#             */
/*   Updated: 2020/11/21 17:21:34 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, int n)
{
	int				index;
	unsigned char	*src_char;
	unsigned char	*dest_char;

	index = 0;
	src_char = (unsigned char *)src;
	dest_char = (unsigned char *)dest;
	while (index < n)
	{
		dest_char[index] = src_char[index];
		if (src_char[index] == (unsigned char)c)
			return (dest + index + 1);
		index++;
	}
	return (NULL);
}
