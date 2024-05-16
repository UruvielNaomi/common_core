/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:57:37 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 09:47:29 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv) 
{
	int				total_philosophers;
	pthread_t		*philosophers;
	pthread_mutex_t	*forks;

	total_philosophers = ft_atoi(argv[1]);
	ft_init_all(**argv, philosophers, forks, total_philosophers);
	ft_destroy_mutex(forks, total_philosophers);
	ft_free_all(philosophers, forks);
	return (0);
}