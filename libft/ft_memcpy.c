/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:19:57 by dscriabi          #+#    #+#             */
/*   Updated: 2020/11/21 16:42:44 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int				index;
	unsigned char	*src_char;
	unsigned char	*dest_char;

	index = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	src_char = (unsigned char *)src;
	dest_char = (unsigned char *)dest;
	while (index < n)
	{
		dest_char[index] = src_char[index];
		index++;
	}
	return (dest);
}
