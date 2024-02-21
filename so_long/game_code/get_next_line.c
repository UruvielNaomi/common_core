/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:53:43 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/21 15:39:32 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*process_and_move(char **remaining)
{
	char	*line;
	char	*newline_char;
	char	*placeholder_remaining;

	if (!*remaining || !**remaining)
		return (NULL);
	newline_char = ft_strchr(*remaining, '\n');
	if (newline_char)
	{
		line = ft_strndup(*remaining, newline_char - *remaining + 1);
		placeholder_remaining = *remaining;
		*remaining = ft_strdup(newline_char + 1);
		free(placeholder_remaining);
	}
	else
	{
		line = ft_strdup(*remaining);
		free(*remaining);
		*remaining = NULL;
	}
	return (line);
}

static char	*read_and_buffer(int fd, char *remaining)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	char	*placeholder_line;

	if (!remaining)
		remaining = ft_strdup("");
	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1 || read_bytes == 0)
		{
			if (read_bytes == 0 && remaining && *remaining)
				return (remaining);
			free(remaining);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		placeholder_line = ft_strjoin(remaining, buffer);
		free(remaining);
		remaining = placeholder_line;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*line;

	remaining = read_and_buffer(fd, remaining);
	line = process_and_move(&remaining);
	return (line);
}
