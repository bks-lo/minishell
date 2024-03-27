/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:51:27 by dscriabi          #+#    #+#             */
/*   Updated: 2020/11/18 16:35:53 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, int n)
{
	int				index;
	unsigned char	*ptr;

	index = 0;
	ptr = (unsigned char *)str;
	while (index < n)
	{
		*ptr = (unsigned char)c;
		ptr++;
		index++;
	}
	return (str);
}
