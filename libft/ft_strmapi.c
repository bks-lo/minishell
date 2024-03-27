/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:53:43 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:44:20 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*return_value;

	if (s == NULL || f == NULL)
		return (NULL);
	return_value = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(return_value))
		return (NULL);
	index = 0;
	while (s[index])
	{
		return_value[index] = f(index, s[index]);
		index++;
	}
	return_value[index] = '\0';
	return (return_value);
}
