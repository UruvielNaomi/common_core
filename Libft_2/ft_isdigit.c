/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:09:56 by nstacia           #+#    #+#             */
/*   Updated: 2023/10/23 13:10:21 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int a;

	a = 'b';
	if (ft_isdigit(a))
		printf("The character is a digit.\n");
	else
		printf("The character is not digit.\n");
	return (0);
}
*/
