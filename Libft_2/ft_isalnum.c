/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:13:15 by nstacia           #+#    #+#             */
/*   Updated: 2023/10/23 13:13:17 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a >= 'a' && a <= 'z')
		|| (a >= 'A' && a <= 'Z')
		|| (a >= 48 && a <= 57))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int = b;

	if (ft_isalnum(n))
		printf("All numbers.\n");
	else
		printf("Not all numbers.\n");
	return (0);
}
*/