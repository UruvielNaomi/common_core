/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:33:21 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/14 10:58:08 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		usleep(100);
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
	}
}

void	send_string(int pid, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
}

int main (int argc, char **argv)
{
	int		pid;
	char	*str;
	
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_string(pid, str);
	return (0);
}

/*
- kill
    This function sends a signal to a specific process or group of processes, 
	in our case to the server.

	int kill(pid_t pid, int sig);



The client takes two parameters:
◦ The server PID. (argv[1])
◦ The string to send (argv[2])
*/