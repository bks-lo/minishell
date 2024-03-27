/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:52:06 by dscriabi          #+#    #+#             */
/*   Updated: 2020/11/19 14:28:48 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, int n)
{
	int				index;
	unsigned char	*str1_char;
	unsigned char	*str2_char;

	index = 0;
	str1_char = (unsigned char *)str1;
	str2_char = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (str1_char[index] == str2_char[index] && index < (n - 1))
		index++;
	return (str1_char[index] - str2_char[index]);
}
