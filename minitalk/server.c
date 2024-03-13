/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:47:17 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/13 14:54:57 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main (void)
{
	ft_prinft("Welcome in the server.\n");
	ft_printf("Server PID is: %d\n", getpid());
	
	// receive string from client
	return (0);
}