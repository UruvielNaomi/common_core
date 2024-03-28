/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_uintptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:51:34 by Naomi             #+#    #+#             */
/*   Updated: 2023/11/21 17:51:34 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_uintptr(uintptr_t n)
{
	char	*hex_digits;
	char	*prefix;
	int		length;
	char	digit;

	hex_digits = "0123456789abcdef";
	prefix = "0x";
	length = 0;
	if (n == 0)
	{
		length += ft_putchar(prefix[0]);
		length += ft_putchar(prefix[1]);
		length += ft_putchar('0');
		return (length);
	}
	if (n >= 16)
		length += ft_puthex_uintptr(n / 16);
	else
	{
		length += ft_putchar(prefix[0]);
		length += ft_putchar(prefix[1]);
	}
	digit = hex_digits[n % 16];
	length += ft_putchar(digit);
	return (length);
}

/*
why are we using uintptr_t and not simpy unsigned int?
- uintptr_t is safer: it can hold any valid pointer
on the given platform. 
- when treating a pointer as a numeric value, its safer.
- 64 bit vs 32 bit. information can get lost when using
an unsigned int. not when using uintptr_t.

if the pointer is NULL the memory address should be 0x0.
*/