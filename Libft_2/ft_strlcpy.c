/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:02:53 by nstacia           #+#    #+#             */
/*   Updated: 2023/10/31 15:02:56 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char src[] = "abcde";
	char dest[6];
	int result;
	result = ft_strlcpy(dest, src, sizeof(char) * 6);
	printf("the length of src = %d\n", result);
	return (0);
}
*/

/*
I is used as an index to traverse the src string.

The while loop runs as long as two conditions are met:
	- There are characters left in the src string (*(src + i) is not a
	null character).
	- The size is greater than 0, indicating that there is space left
	in the dest buffer.

--size is used to decrement size before entering the loop to ensure
that there's enough space for the null terminator ('\0') in the
destination buffer.

Inside the loop, characters from the src string are copied to the
dest string, and both pointers (dest and src) are incremented to
point to the next character in each string. This process continues
as long as the conditions in the while loop are met.

After the loop, a null terminator ('\0') is explicitly added to
the dest buffer to ensure that the copied data forms a valid C string.

To determine the length of the original src string, another while
loop is used. This loop continues where the previous loop left off
and increments i until a null character is encountered in the src
string. The value of i at the end of this loop represents the length
of the original src string.

Finally, the function returns the value of i, which is the length
of the src string.*/