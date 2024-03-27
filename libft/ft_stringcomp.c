/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringcomp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:33:31 by romain            #+#    #+#             */
/*   Updated: 2022/01/25 19:37:53 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**returns 0 if identical
*/

int	ft_stringcomp(const char *str1, const char *str2)
{
	if (!str1 && !str2)
		return (0);
	if (!str1 || !str2)
		return (-1);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (-1);
	return (ft_strncmp(str1, str2, ft_strlen(str1)));
}
