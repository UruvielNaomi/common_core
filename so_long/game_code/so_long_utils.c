/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:33:59 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/03 18:48:11 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void	*dest, void const *src, size_t len)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	dest_ptr = dest;
	src_ptr = src;
	if (!dest && !src)
		return (dest);
	while (len > 0)
	{
		*dest_ptr++ = *src_ptr++;
		len--;
	}
	return (dest);
}

static void	*ft_memset(void *memory_block, int value, size_t num_bytes)
{
	unsigned char	*byte_pointer;

	byte_pointer = (unsigned char *)memory_block;
	while (num_bytes--)
		*byte_pointer++ = (unsigned char)value;
	return (memory_block);
}
