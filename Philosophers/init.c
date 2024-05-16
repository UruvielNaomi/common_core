/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:09:55 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 10:20:30 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_forks(pthread_mutex_t **forks, int total_philosophers)
{
	int i;

	i = 0;
	*forks = malloc(total_philosophers * sizeof(pthread_mutex_t));
	while (i < total_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	ft_init_all(char **argv, pthread_t **philosophers, pthread_mutex_t **forks, int total_philosophers)
{
	int					i;
	t_philosopher_info *info;
	
	i = 0;
	info = malloc(total_philosophers * sizeof(t_philosopher_info));
	*philosophers = malloc(total_philosophers * sizeof(pthread_t));
	ft_init_fork(forks, total_philosophers);
	while (i < total_philosophers)
	{
		info[i].personal_id = i;
		info[i].total_philosophers = total_philosophers;
		info[i].forks = forks;
		info[i].eat_count = 0;
		info[i].die_time = ft_atoi(argv[2]);
		info[i].eat_time = ft_atoi(argv[3]);
		info[i].sleep_time = ft_atoi(argv[4]);
		if (argv[5])
			info[i].total_eat = ft_atoi(argv[5]);
		pthread_create(&philosophers[i], NULL, philosopher_function, (void*)&info[i]);
		i++;
	}
	ft_join_threads(philosophers, total_philosophers);
}
