/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:40:06 by dscriabi          #+#    #+#             */
/*   Updated: 2020/11/21 16:47:05 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, int n)
{
	int					index;
	unsigned char		*str1_char;
	const unsigned char	*str2_char;

	str1_char = (unsigned char *)str1;
	str2_char = (unsigned char *)str2;
	index = 0;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str2_char < str1_char)
		while (++index <= n)
			str1_char[n - index] = str2_char[n - index];
	else
		while (n-- > 0)
			*(str1_char++) = *(str2_char++);
	return (str1);
}
