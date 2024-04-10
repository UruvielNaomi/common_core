/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:04:00 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/15 12:04:02 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	ssize_t	check;

	check = write(1, &c, 1);
	if (check == -1)
		return (-1);
	else
		return (1);
}

/* 
When you pass a char argument to putchar, the char is implicitly
promoted to an int, and the ASCII value of the character is used.
*/