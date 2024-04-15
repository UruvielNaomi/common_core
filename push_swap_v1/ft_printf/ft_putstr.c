/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:08:47 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/15 12:08:51 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	length;

	length = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[length])
	{
		write(1, &str[length], 1);
		length++;
	}
	return (length);
}
