/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:54:35 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/25 15:42:43 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		index;
	int		count;

	count = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == '\0'))
			count++;
		index++;
	}
	return (count);
}

static int	ft_word_length(char const *s, char c)
{
	int		index;
	int		length;

	index = 0;
	length = 0;
	while (s[index] != c && s[index] != '\0')
	{
		index++;
		length++;
	}
	return (length);
}

void	*ft_free_split(char **split_str, int word_count)
{
	int	index;

	index = 0;
	while (index < word_count)
	{
		free(split_str[index]);
		index++;
	}
	free(split_str);
	return (NULL);
}

static char	**ft_fill_str(char const *s, int wc, char c, char **s_str)
{
	int		index;
	int		sub_index;
	int		length;

	index = -1;
	while (++index < wc)
	{
		while (*s == c)
			s++;
		length = ft_word_length(s, c);
		s_str[index] = (char *)malloc(sizeof(char) * (length + 1));
		if (!(s_str[index]))
			return (ft_free_split(s_str, index));
		sub_index = 0;
		while (sub_index < length)
			s_str[index][sub_index++] = *s++;
		s_str[index][sub_index] = '\0';
	}
	s_str[index] = NULL;
	return (s_str);
}

char	**ft_split(char	const *s, char c)
{
	char	**split_str;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	split_str = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!(split_str))
		return (NULL);
	split_str = ft_fill_str(s, word_count, c, split_str);
	return (split_str);
}
