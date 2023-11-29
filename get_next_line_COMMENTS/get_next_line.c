/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:19:35 by Naomi             #+#    #+#             */
/*   Updated: 2023/11/29 13:05:37 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*process_buffer(char **remaining) // Function returns a pointer to a character. **changing the location of the original pointer
{
	char	*line;              // line we need to return
	char	*newline_char;      // newline_char we need to find in remaining
    char	*old_remaining;     // create pointer that we will use to store pointer remaining in, while we move that pointer.

	if (!*remaining || !**remaining) // if remaining is empty or doesn't point to a valid character
		return (NULL);
	newline_char = ft_strchr(*remaining, '\n'); // search for the newline char in remaining indicating end of the line, start of new line.
	if (newline_char) //if you have found it a newline character
	{
		line = ft_strndup(*remaining, newline_char - *remaining + 1); // line being created by duplicating the characters from the start of remaining up to and including the newline character
        old_remaining = *remaining; // store pointer of remaining in old remaining
		*remaining = ft_strdup(newline_char + 1); // duplicate the string starting from the first character after the '\n'.
        free(old_remaining); // deallocate old remaining (question: why do we need this whole process with old remaining, it feels redundant.)
		// Answer: This process is necessary because we are changing the pointer *remaining to point to a new location (the character after '\n'). 
		// The old memory that *remaining was pointing to is no longer needed, so we free it to prevent memory leaks.
	}
	else // if no newline char is found (which probably means we are at the end of the file)
	{
		line = ft_strdup(*remaining); // duplicate the remaining string into line
		free(*remaining); // deallocate memory
		*remaining = NULL; // setting pointer to NULL (0x0??)
		// Answer: Yes, setting *remaining to NULL means it points to memory address 0x0. It's a common practice to indicate that the pointer is not intended to point to a readable memory location.
	}
	return (line); // return the line
}

char	*read_and_buffer(int fd, char *remaining)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	char	*temp;

	if (!remaining) // if remaining is null (from previous call)
		remaining = ft_strdup(""); // initialize to empty string.
	while (1) // create loop
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1 || read_bytes == 0) // -1 = fail during read || 0 = nothing has been read (empty)
		{
			if (read_bytes == 0 && remaining && *remaining) // if 0 read && remaining is not null and points to a valid character
				return (remaining); // return remaining: a pointer to a character string that contains the part of the file that has been read but not yet processed, in this case the whole text.
			free(remaining); //free the memory because read has failed
			return (NULL); //return NULL to indicate fail
		}
		buffer[read_bytes] = '\0'; // null terminate buffer
		temp = ft_strjoin(remaining, buffer); // concatenate data from buffer to the end of remaining.
		free(remaining); // deallocate remaining
		remaining = temp; // remaining now points to memory block temp.
		if (ft_strchr(buffer, '\n')) // search the buffer for newline character
			break ; // if it has found, break from this loop.
	}
	return (remaining); // return the string made by string join including the newline character.
}

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*line;

	remaining = read_and_buffer(fd, remaining); //send file and remaining text.
	line = process_buffer(&remaining); // passing the memory address of remaining
	return (line);
}


/*
In the read_and_buffer function, remaining is used to store any 
unprocessed data from the previous read operation. 
This is the data that comes before the next newline character.

In the process_buffer function, remaining is used to store any
data that comes after the  first newline character in the buffer. 
This is the data that will be processed in the next call to get_next_line.

Pointer to a pointer in a function: often done to modify the 
original pointer by updating its memory address.

line = ft_strndup(*remaining, newline_char - *remaining + 1)
Subtracting the "earlier" pointer from the "further" pointer 
gives a positive result,  indicating the number of elements between them.
+ 1 for '\n'.

if (!*remaining || !**remaining):
1. checks if the pointer remaining itself is NULL.
2. checks if the string that remaining points to is empty.


cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 
get_next_line.c get_next_line_utils.c -o gnl

*/

