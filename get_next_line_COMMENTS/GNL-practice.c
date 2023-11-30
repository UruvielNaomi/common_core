#include "get_next_line.h"

char *process_line(char **remaining)
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

char	*read_and_find(int fd, char *remaining)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t bytes_read;
	char	*placeholder_line;

	if (!remaining)
		remaining = NULL;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 || bytes_read == -1)
		{
			if (bytes_read == 0 && remaining && *remaining) //nothing read, remaining has content and valid pointer aka end of the text
				return (remaining);
			free(remaining);
			return (NULL);
		}
		placeholder_line = ft_strjoin(remaining, buffer);
		free (remaining);
		remaining = placeholder_line;
		if (ft_strchr(remaining, '\n'))
			break ;
	}
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*line;

	remaining = read_and_find(fd, remaining);
	line = process_line(&remaining);

	return (line);
}