/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:50:40 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/21 16:43:46 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/syscall.h>
# include <signal.h>

struct {
	int		bits;
	char	character;
}			s_server;

int	ft_atoi(const char *str);

#endif
