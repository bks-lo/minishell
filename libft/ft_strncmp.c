/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:25:09 by dscriabi          #+#    #+#             */
/*   Updated: 2020/11/21 19:48:16 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, int n)
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
	{
		if (!str1_char[index] || !str2_char[index])
			break ;
		index++;
	}
	return (str1_char[index] - str2_char[index]);
}
