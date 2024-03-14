/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:47:17 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/14 10:58:56 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

void	bit_to_string(int bit)
{
	
}

int main (void)
{
	ft_prinft("Welcome in the server.\n");
	ft_printf("Server PID is: %d\n", getpid());
	
	while (1)
	{
		signal(SIGUSR1, bit_to_string);
		signal(SIGUSR2, bit_to_string);

		// signal/sigaction??

	}
	return (0);
}