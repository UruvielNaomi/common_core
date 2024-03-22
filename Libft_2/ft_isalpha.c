/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:09:23 by nstacia           #+#    #+#             */
/*   Updated: 2023/10/23 13:09:41 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	char	str[] = "hallo2";

	if (ft_isalpha(str))
		printf("Contains only alphabetic characters.\n");
	else
		printf("Contains non-alphabetic characters.\n");
	return (0);
}
*/
