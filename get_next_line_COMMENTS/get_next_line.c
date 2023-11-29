/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:19:35 by Naomi             #+#    #+#             */
/*   Updated: 2023/11/29 08:49:38 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *process_buffer(char **remaining) // *Function returns a pointer to a character. **changing the location of the original pointer
{
    char *line;
    char *newline_char;
    char *next_char;
    char *old_remaining;

    newline_char = ft_strchr(*remaining, '\n'); //search for newline character, ptr now points to its location in remaining
    if (newline_char)//if found-->a completed line present remaining.
    {
        line = ft_strndup(*remaining, newline_char - *remaining); //duplicate portion of the string from start of remaining to just before '\n'. why newline_char - *remaining: newline ptr is further along than remaining, deduct to get the number of elements between pointers.
        old_remaining = *remaining;
        *remaining = ft_strdup(newline_char + 1);
        free(old_remaining);
    }
    else
    {
        line = ft_strdup(*remaining);
        free(*remaining);
        *remaining = ft_strdup("");
    }
    return (line);
}

char	*read_and_buffer(int fd, char *remaining)
{
    char	buffer[BUFFER_SIZE + 1];
    ssize_t	read_bytes;
    char    *temp;

    if (!remaining) // if remaining is null (from previous call), we initialize to an empty string.
        remaining = NULL;
    while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0) // as long as there is something in the file, keep going in this loop.
    {
        if (read_bytes == -1) //-1 means: error in read operation
            return (NULL);
        buffer[read_bytes] = '\0'; // nul terminate data in the buffer.
        temp = ft_strjoin(remaining, buffer); //append the data from the buffer to the end of the “remaining” string. The result is stored in a temporary string 
        if (!temp)
            return (NULL);
        free (remaining); //deallocate memory, temp has its contents.
        remaining = temp; //remaining is now pointing to the new block of memory.
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    return (remaining);
}

char	*get_next_line(int fd)
{
    static char	*remaining;
    char		*line;
    char        *line_copy;

    remaining = read_and_buffer(fd, remaining);
    line = process_buffer(&remaining); // passing the memory address of remaining
    line_copy = line;
    free(line);
    return (line_copy);
}


/*
In the read_and_buffer function, remaining is used to store any unprocessed data from 
the previous read operation. This is the data that comes before the next newline character.

In the process_buffer function, remaining is used to store any data that comes after the 
first newline character in the buffer. This is the data that will be processed in the next call to get_next_line.

When you use a pointer to a pointer in a function, you often do so because you want 
to modify the original pointer by updating its memory address.

line = ft_strndup(*remaining, newline_char - *remaining)
Subtracting the "earlier" pointer from the "further" pointer gives a positive result, 
indicating the number of elements between them.
*/