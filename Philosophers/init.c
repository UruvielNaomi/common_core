/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:09:55 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 16:18:47 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_forks(pthread_mutex_t **forks, int total_phil)
{
	int	i;

	i = 0;
	*forks = malloc(total_phil * sizeof(pthread_mutex_t));
	while (i < total_phil)
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		i++;
	}
}

void	ft_init_all(char **argv, pthread_t **phil, \
	pthread_mutex_t **forks, int total_phil)
{
	int					i;
	t_philosopher_info	*info;

	i = 0;
	info = malloc(total_phil * sizeof(t_philosopher_info));
	*phil = malloc(total_phil * sizeof(pthread_t));
	ft_init_forks(forks, total_phil);
	while (i < total_phil)
	{
		info[i].id = i;
		info[i].nr = i + 1;
		info[i].total_phil = total_phil;
		info[i].forks = *forks;
		info[i].eat_count = 0;
		info[i].eat_flag = 0;
		info[i].die_time = ft_atoi(argv[2]);
		info[i].eat_time = ft_atoi(argv[3]);
		info[i].sleep_time = ft_atoi(argv[4]);
		if (argv[5])
			info[i].total_eat = ft_atoi(argv[5]);
		pthread_create(&(*phil)[i], NULL, phil_function, (void *)&info[i]);
		i++;
	}
	ft_join_threads(phil, total_phil);
}
