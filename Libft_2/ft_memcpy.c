/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:18:17 by nstacia           #+#    #+#             */
/*   Updated: 2023/10/24 12:18:18 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
int main(void)
{
	char src[] = "abcde";
	char dest[6];
	
	ft_memcpy(dest, src, sizeof(char) * 6);
	printf("dest = %s\n", dest);
	return (0);
}
*/