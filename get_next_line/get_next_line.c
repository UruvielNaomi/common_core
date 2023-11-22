/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:47:42 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/22 15:27:36 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
		
}
int main (void)
{
	open();
	return (0);
}
/*
A file descriptor is a reference that points to a file that is open on your computer. 

In the function we build, we send this file descriptor (the reference to the file).
- We tell it to check that file and return us a string of character:
	the line that was read from the file. 
loop through the file, line by line, until done.
*/

/*

It is a function that reads a file and allows you to read a line ending with a 
newline character from a file descriptor. When you call the function again on 
the same file, it grabs the next line. This project deals with memory allocation 
and when to free and allocate memory to prevent leaks.

A (-1) is returned if an error occurred. A (0) is returned if the file is 
finished reading. And a (1) is returned if a line is read.

Parameters 
	fd: The file descriptor to read from

Return value 
	Read line: correct behavior
	NULL: there is nothing else to read, or an error occurred

External functs. 
	read, malloc, free

Description 
	Write a function that returns a line read from a file descriptor

BUFFER_SIZE typically represents the size of the buffer that you use to read data 
from a file descriptor (using the read function in your case). The buffer is a 
temporary storage area in memory where you read a chunk of data from the file.


Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
• Make sure that your function works as expected both when reading a file and when
reading from the standard input.
• Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.
• Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.
• Add all the helper functions you need in the get_next_line_utils.c file.


*/