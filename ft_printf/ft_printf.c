/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:48:36 by nstacia           #+#    #+#             */
/*   Updated: 2024/05/02 13:00:36 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checktype(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (format == 'x' || format == 'X')
		length += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == 'i' || format == 'd')
		length += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		length += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == 'p')
		length += ft_puthex_uintptr(va_arg(args, uintptr_t));
	else if (format == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, format);
	if (!format)
		length = -1;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			length += ft_checktype(args, format[i]);
		}
		else
			length += ft_putchar(format[i]);
		i++;
	}
	return (length);
}

/*

TO ADD:
-	%p The void * pointer argument has to be printed in hexadecimal format


return value is the number of characters that it printed (excl the null byte)

-	va_arg(the_list, wanted_output)--> used to pull out arguments.
	example: va_arg(args, int) --> our list is called args, int wanted output.

ft_puthex is receiving two arguments: 
1.		the value to be printed: (va_arg(args, unsigned int)) 
2. 		the format specifier (format) which indicates whether 
		the hexadecimal output should be in lower case (‘x’) 
		or upper case (‘X’).
*/
