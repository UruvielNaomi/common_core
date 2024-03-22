/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:31:07 by nstacia           #+#    #+#             */
/*   Updated: 2023/10/24 15:31:09 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	int				direction;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	direction = 1;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		direction = -1;
		d += len - 1;
		s += len - 1;
	}
	while (i < len)
	{
		*d = *s;
		d += direction;
		s += direction;
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "abcde";
	char	dest[6];

	ft_memmove(dest, src, 6);
	printf("dest = %s\n", dest);
	return (0);
}
*/

/*
Since direction is -1, the increment operation (d += direction and 
s += direction) effectively behaves as a decrement operation, 
ensuring that the data is copied from the end to the beginning 
without data loss.

When dest is greater than src, the code sets direction to -1. This is a 
signal to the subsequent logic in the code that reversed copying is needed.

The code uses the direction variable to adjust the d and s pointers. 
When direction is -1, the pointers are incremented, but the effect of 
incrementing with -1 is that they effectively move in the opposite direction, 
allowing reversed copying from the end of the memory block to the beginning.
*/