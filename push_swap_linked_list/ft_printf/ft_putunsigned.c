/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:01:01 by Naomi             #+#    #+#             */
/*   Updated: 2023/11/21 18:01:01 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putunsigned_recursive(unsigned int n, int *length)
{
	if (n >= 10)
	{
		ft_putunsigned_recursive(n / 10, length);
		ft_putunsigned_recursive(n % 10, length);
	}
	else
		*length += ft_putchar(n + '0');
	return (*length);
}

int	ft_putunsigned(unsigned int n)
{
	int	length;

	length = 0;
	return (ft_putunsigned_recursive(n, &length));
}
