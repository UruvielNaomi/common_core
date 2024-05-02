/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:53:03 by nstacia           #+#    #+#             */
/*   Updated: 2024/05/02 12:26:43 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int	ft_putnbr_recursive(int n, int *length)
{
	if (n == INT_MIN)
	{
		*length += ft_putchar('-');
		*length += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		*length += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_recursive(n / 10, length);
		ft_putnbr_recursive(n % 10, length);
	}
	else
		*length += ft_putchar(n + '0');
	return (*length);
}

int	ft_putnbr(int n)
{
	int	length;

	length = 0;
	return (ft_putnbr_recursive(n, &length));
}
*/
/*
When you declare a pointer variable, such as int *length, 
the * in front of the variable is used for dereferencing the 
pointer. Dereferencing means accessing the value stored at 
the memory address pointed to by the pointer.

In the ft_putnbr_recursive function, *length is used to 
dereference the pointer and access the actual value of length 
stored in memory. This allows us to update the value of length directly.

When calling the function recursively, we pass the pointer 
itself (not the dereferenced value) as an argument.
*/

int	ft_putnbr(int n)
{
	static int length = 0;

	if (n == INT_MIN)
	{
		length += ft_putchar('-');
		length += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		length += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		length += ft_putchar(n + '0');

	return length;
}
