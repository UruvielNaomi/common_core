#include "get_next_line.h"

char	*ft_process_and_move(char **remaining)
{
	char	*line;
	char	*newline_char;
	char	*placeholder_remaining;

	if (!*remaining && !**remaining)
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

char	*ft_read_and_find(int fd, char *remaining)
{
	ssize_t	bytes_read;
	char	*placeholder_line;
	char	buffer[BUFFER_SIZE + 1];

	if (!remaining)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 || bytes_read == -1)
		{
			if (bytes_read == 0 && remaining && *remaining)
				return (remaining);
			free(remaining);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		placeholder_line = ft_strjoin(remaining, buffer);
		free(remaining);
		remaining = placeholder_line;
		if (ft_strchr(remaining, '\n'))
			break ;
	}
	return (remaining);
}

char *get_next_line(int fd)
{
	static char	*remaining;
	char		*line;

	remaining = ft_read_and_find(fd, remaining);
	line = ft_process_and_move(&remaining);

	return (line);
}