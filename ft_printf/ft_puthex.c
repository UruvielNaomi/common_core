/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:30:56 by nstacia           #+#    #+#             */
/*   Updated: 2024/05/02 15:03:00 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, const char format)
{
	char		*hex_digits;
	static int	length;
	char		digit;

	hex_digits = "0123456789abcdef";
	length = 0;
	if (n >= 16)
	{
		ft_puthex(n / 16, format);
	}
	digit = hex_digits[n % 16];
	if (format == 'X')
		digit = ft_toupper(digit);
	length += ft_putchar(digit);
	return (length);
}

/*
without use of static int

int	ft_puthex(unsigned int n, const char format)
{
	char		*hex_digits;
	int	length;
	char		digit;

	hex_digits = "0123456789abcdef";
	length = 0;
	if (n >= 16)
	{
		length += ft_puthex(n / 16, format);
	}
	digit = hex_digits[n % 16];
	if (format == 'X')
		digit = ft_toupper(digit);
	length += ft_putchar(digit);
	return (length);
}
*/