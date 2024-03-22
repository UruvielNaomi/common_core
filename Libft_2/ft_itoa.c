/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:05:28 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/10 12:05:31 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(char *array, int *i, int n)
{
	if (n >= 10)
	{
		ft_putnbr(array, i, n / 10);
		ft_putnbr(array, i, n % 10);
	}
	else
	{
		array[*i] = n + '0';
		(*i)++;
	}
}

static size_t	ft_countdigits(int n)
{
	size_t	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	int		is_negative;
	char	*array;
	size_t	count;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	is_negative = (n < 0);
	if (is_negative)
		n = -n;
	count = ft_countdigits(n) + is_negative;
	array = (char *)malloc(sizeof(char) * (count + 1));
	if (!array)
		return (NULL);
	i = 0;
	if (is_negative)
		array[i++] = '-';
	ft_putnbr(array, &i, n);
	array[i] = '\0';
	return (array);
}

/*
NOTES ON CODE:
	- why use the & (line 44)
		we need to pass the address because we want
		the changes made to i in putnbr to reflect
		in ft_itoa. 
		If i is passed instead of &i, the function would
		be working with a copy of i. therefore, changes 
		made to i in ft_putnbr would not affect the value 
		of i in ft_itoa.
	- why use * infront of i (line 10 & 11)
		to dereference a pointer so we can access the value
		of i and increment the array for the next digit.

	- recursive method
		We use the recursive method, therefore numbers
		are not put in backwards. 

*/
/*
Assignment:
parameter: n: the integer to convert to array.

return value: the string representing the integer.
if allocation fails NULL.

Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.


Atoi vs Itoa
Atoi:
	- string to int.
	- it already excist in the memory.
	- no additional memeory needs to be allocated.

Itoa:
	- int to new string.
	- string doesn't exist yet: new memory is needed.
	- itoa checks the number of digits + 1 for null terminator.
	- allocate enough memory to hold the string
		representation of the int.

*/