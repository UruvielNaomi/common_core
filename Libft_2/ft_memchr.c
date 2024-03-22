/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:17:52 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/01 15:18:10 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		uc;

	ptr = (unsigned char *)str;
	uc = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

/*
int main() {
    const char *str = "Hello, World!";
    char target = 'u';

    void *result = ft_memchr(str, target, 13);

    if (result != NULL)
        printf("Found '%c' at position %ld\n", target, (char *)result - str);
    else
        printf("Char '%c' not found in the string.\n", target);
    return (0);
}
*/
/*
	The memchr() function locates the first occurrence of c (converted to 
	an unsigned char) in string s.
	The memchr() function returns a pointer to the byte located, or NULL if 
	no such byte exists within n bytes.
*/

/*
	The key difference between strchr() and memchr():
 	- 	strchr() is for finding characters in null-terminated strings.
	- 	memchr() is for searching for bytes within a memory block of a specified 
		size, which is not limited to null-terminated strings.
*/