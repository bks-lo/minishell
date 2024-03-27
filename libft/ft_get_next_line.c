/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitriscr <dimitriscr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:15:49 by dscriabi          #+#    #+#             */
/*   Updated: 2022/02/17 17:30:35 by dimitriscr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*remove_end_prev_line(char *str)
{
	int		i;
	int		j;
	char	*return_chars;

	i = 0;
	if (!str || str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	i += (str[i] == '\n');
	return_chars = malloc(sizeof(char) * ((ft_gnl_strlen(str) - i) + 1));
	if (!return_chars)
		return (NULL);
	j = 0;
	while (str[i])
		return_chars[j++] = str[i++];
	return_chars[j] = '\0';
	free(str);
	return (return_chars);
}

char	*remove_start_next_line(char *str)
{
	int		i;
	char	*return_chars;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	return_chars = malloc(sizeof(char) * (i + 2));
	if (!return_chars)
		return (NULL);
	i = 0;
	while (str[i])
	{
		return_chars[i] = str[i];
		i++;
		if (i > 0 && str[i - 1] == '\n')
			break ;
	}
	return_chars[i] = '\0';
	return (return_chars);
}

int	has_slash_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*prev_chars;
	char		*buffer;
	int			chars_read;

	chars_read = 1;
	if (fd < 0 || GNL_BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * GNL_BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!has_slash_n(prev_chars) && chars_read)
	{
		chars_read = read(fd, buffer, GNL_BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[chars_read] = '\0';
		prev_chars = ft_gnl_strjoin(prev_chars, buffer);
	}
	free(buffer);
	buffer = remove_start_next_line(prev_chars);
	prev_chars = remove_end_prev_line(prev_chars);
	return (buffer);
}

int	ft_get_next_line(int fd, char **out_str, int *len)
{
	static char	*prev_chars;
	char		*buffer;
	int			chars_read;


	chars_read = 1;
	if (fd < 0 || GNL_BUFFER_SIZE <= 0 || *out_str == NULL)
		return -1; 
	buffer = malloc(sizeof(char) * GNL_BUFFER_SIZE + 1);
	if (!buffer)
		return -1;
	while (!has_slash_n(prev_chars) && chars_read)
	{
		chars_read = read(fd, buffer, GNL_BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buffer);
			return -1;
		}
		buffer[chars_read] = '\0';
		prev_chars = ft_gnl_strjoin(prev_chars, buffer);
	}
	free(buffer);
	buffer = remove_start_next_line(prev_chars);
	prev_chars = remove_end_prev_line(prev_chars);

	*out_str = buffer;
	if (len != NULL) {
		*len = ft_strlen(buffer);
	}

	return 0;
}
