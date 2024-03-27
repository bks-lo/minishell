/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:27:59 by dscriabi          #+#    #+#             */
/*   Updated: 2020/11/24 19:59:03 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	src_len;
	unsigned int	index;

	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	index = 0;
	if (n <= 0)
		return (src_len);
	while (index < src_len && index < n - 1)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (src_len);
}
