/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:53:43 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/29 14:04:31 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*process_buffer(char **remaining)
{
	char	*line;
	char	*newline_char;
	char	*old_remaining;

	if (!*remaining || !**remaining)
		return (NULL);
	newline_char = ft_strchr(*remaining, '\n');
	if (newline_char)
	{
		line = ft_strndup(*remaining, newline_char - *remaining + 1);
		old_remaining = *remaining;
		*remaining = ft_strdup(newline_char + 1);
		free(old_remaining);
	}
	else
	{
		line = ft_strdup(*remaining);
		free(*remaining);
		*remaining = NULL;
	}
	return (line);
}

char	*read_and_buffer(int fd, char *remaining)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	char	*temp;

	if (!remaining)
		remaining = NULL;
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
		temp = ft_strjoin(remaining, buffer);
		free(remaining);
		remaining = temp;
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
	line = process_buffer(&remaining);
	return (line);
}
/*
int main(void)
{
    int fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error creating file");
        return 1;
    }
    const char *text = "This is line 1.\nThis is line 2.\nThis is line 3.";
    if (write(fd, text, ft_strlen(text)) == -1)
    {
        perror("Error writing to file");
        close(fd);
        return 1;
    }
    close(fd);
    fd = open("test_file.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line read: %s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}*/

/*
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 
get_next_line.c get_next_line_utils.c -o gnl

*/