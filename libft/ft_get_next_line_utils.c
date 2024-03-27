/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:16:09 by dscriabi          #+#    #+#             */
/*   Updated: 2021/11/10 16:59:44 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_gnl_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		total_len;
	char	*return_str;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_gnl_strlen((char *)s1);
	s2_len = ft_gnl_strlen((char *)s2);
	total_len = s1_len + s2_len + 1;
	return_str = malloc(sizeof(char) * total_len);
	if (!return_str)
		return (NULL);
	ft_gnl_memmove(return_str, s1, s1_len);
	ft_gnl_memmove(return_str + s1_len, s2, s2_len);
	return_str[total_len - 1] = '\0';
	if (s1)
		free((char *)s1);
	return (return_str);
}

size_t	ft_gnl_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
