/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:01:33 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:43:54 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	offset;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	index = 0;
	offset = dest_len;
	while (src[index] != '\0' && offset < size - 1 && size != 0)
	{
		dest[offset] = src[index];
		offset++;
		index++;
	}
	dest[offset] = '\0';
	if (size <= dest_len)
		return (src_len + size);
	else
		return (dest_len + src_len);
}
