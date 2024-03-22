/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:30:35 by nstacia           #+#    #+#             */
/*   Updated: 2023/10/23 13:30:37 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 0177)
		return (1);
	else
		return (0);
}

/* 
The isascii() function tests if a given character, in the current locale, 
can be represented as a valid 7–bit US-ASCII character.

So we need to use base 8 (Octal) — Represent any number using 8 digits [0–7].
*/
