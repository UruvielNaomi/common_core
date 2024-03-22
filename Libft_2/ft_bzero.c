/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:52:52 by nstacia           #+#    #+#             */
/*   Updated: 2023/10/24 11:52:53 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (len > 0)
	{
		*ptr = '\0';
		ptr++;
		len--;
	}
}

/*
DESCRIPTION
The bzero() function writes n zeroed bytes to the string s.  
If n is zero, bzero() does nothing.

RETURN VALUE
The bzero() function shall not return a value.

A null byte is a char having a value of exactly zero, noted as '\0'.
*/