/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:47:17 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/14 18:59:51 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void bit_to_string(int signum)
{
    received.character <<= 1;  // Shift the bits to the left to make space for the new bit.
    if (signum == SIGUSR2) {
        received.character |= 1;  // Set the least significant bit to 1. if we receive sigusr1, we do nothing, because we already shifted the bits to the left, leaving a 0 at the end.
    }
    received.bits++;
    if (received.bits == 8) {
        ft_printf("%c", received.character);
		if (received.character == '\0')
			ft_print("\n");
        received.bits = 0;
        received.character = 0;
    }
}

int main (void)
{
	received.bits = 0;
	received.character = 0;
	ft_prinft("Welcome in the server.\n");
	ft_printf("Server PID is: %d\n", getpid());
	
	while (1)
	{
		signal(SIGUSR1, bit_to_string);
		signal(SIGUSR2, bit_to_string);
		pause(); // we are in an infinite loop, so we need to pause the program until it receives a signal.
	}
	return (0);
}

/*

signal() used for seeting up signal handles in client and server, arguments: signal, function to call.
so for example:
signal(SIGUSR1, handler)--> when SIGUSR1 is received, the function handler is called.


In C char is 1 byte: can hold values from 0 to 255 (in the case of unsigned char) or -128 to 127 (in the case of signed char).
when assigning 0 to a char, it get's the smallest possible value, when printed it will be the null character. 

\When you’re using the char to accumulate bits, you’re not thinking of it as a character but as a small integer. So, the 0 is just the integer value 0, not the null character.
*/