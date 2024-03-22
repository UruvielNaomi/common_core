/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:36:06 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/03 14:36:10 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			total_size;
	size_t			i;

	total_size = count * size;
	i = 0;
	temp = malloc (total_size);
	if (!temp)
		return (NULL);
	while (i < total_size)
		temp[i++] = 0;
	return (temp);
}

/*
The calloc() function contiguously allocates enough space for count objects that 
are size bytes of memory each and returns a pointer to the allocated memory. 
The allocated memory is filled with bytes of value zero.
*/

// why an unsigned char ptr and not a void ptr???