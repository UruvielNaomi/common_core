/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:47:17 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/15 15:06:44 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_string(int signum)
{
	s_received.character <<= 1;
	if (signum == SIGUSR2)
		s_received.character |= 1;
	s_received.bits++;
	if (s_received.bits == 8)
	{
		ft_printf("%c", s_received.character);
		if (s_received.character == '\0')
			ft_print("\n");
		s_received.bits = 0;
		s_received.character = 0;
	}
}

int	main(void)
{
	s_received.bits = 0;
	s_received.character = 0;
	ft_prinft("Welcome in the server.\n");
	ft_printf("Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, bit_to_string);
		signal(SIGUSR2, bit_to_string);
		pause();
	}
	return (0);
}
