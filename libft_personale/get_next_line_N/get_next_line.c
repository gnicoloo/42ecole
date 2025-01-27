/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:28:55 by gnicolo           #+#    #+#             */
/*   Updated: 2024/12/19 15:19:23 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*ft_trim_line(char *line_full, char **sub_str)
{
	size_t	len;
	char	*pool;

	len = 0;
	pool = 0;
	if (!line_full)
		return (NULL);
	while (line_full[len] != '\n' && line_full[len] != 0)
		len++;
	pool = ft_substr(line_full, 0, len + 1);
	*sub_str = ft_substr(line_full, len + 1, ft_strlen(line_full) - len);
	free(line_full);
	return (pool);
}

char	*ft_cool_line(int fd, char *buffer, char *sub_str)
{
	int		read_bytes;
	char	*new_temp;

	while (!ft_strchr(sub_str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0 && sub_str[0] == '\0')
			return (free(buffer), NULL);
		if (read_bytes == 0)
			return (free(buffer), sub_str);
		else if (read_bytes < 0)
			return (free(buffer), free(sub_str), NULL);
		buffer[read_bytes] = '\0';
		new_temp = ft_strjoin(sub_str, buffer);
		if (new_temp == NULL)
			return (free(buffer), NULL);
		sub_str = new_temp;
	}
	return (free(buffer), sub_str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;

	i = 0;
	s = malloc(size * nmemb);
	if (s == NULL)
		return (NULL);
	while (i < (size * nmemb))
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*sub_str;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (sub_str == NULL)
		sub_str = ft_strdup("");
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_cool_line(fd, buffer, sub_str);
	if (!line)
	{
		free(sub_str);
		sub_str = NULL;
		return (NULL);
	}
	line = ft_trim_line(line, &sub_str);
	if (!line)
		return (NULL);
	return (line);
}

