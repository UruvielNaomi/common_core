/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:30:29 by nstacia           #+#    #+#             */
/*   Updated: 2023/10/24 10:30:30 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (len > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (str);
}
/*
int	main(void)
{
	char str[] = "Testing";
	int c = 33;
	size_t len = 2;

	ft_memset(str, c, len);
	printf("Modified string: %s\n", str);
	return (0);
}
*/

//	Yes, in your ft_memset function, the return value is the starting address 
// 	of the memory block pointed to by the str parameter. 