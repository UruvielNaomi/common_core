/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:21:58 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 16:27:27 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philosopher_info *info, int left_fork, int right_fork)
{
	long	elapsed_time;

	pthread_mutex_lock(&info->forks[left_fork]);
	ft_time_stamps(info, 1);
	if (pthread_mutex_lock(&info->forks[right_fork]) != 0)
		pthread_mutex_unlock(&info->forks[left_fork]);
	else
	{
		ft_time_stamps(info, 1);
		gettimeofday(&info->end, NULL); // get the end time
		elapsed_time = calculate_elapsed_time(info->start, info->end);
		if (elapsed_time > info->die_time) // starved
		{
			ft_time_stamps(info, 5);
			return (NULL); // end of function
		}
		gettimeofday(&info->start, NULL);
		ft_time_stamps(info, 2);
		usleep(info->eat_time);// eating...
		info->eat_flag = 1;
		pthread_mutex_unlock(&info->forks[right_fork]); // 
		pthread_mutex_unlock(&info->forks[left_fork]); // put down left fork
		gettimeofday(&info->start, NULL); // reset start after successful eating
	}
}

void	ft_sleep(t_philosopher_info *info)
{
	ft_time_stamps(info, 3);
	usleep(info->sleep_time);
	info->eat_flag = 0;
	info->eat_count += 1;
}

void	*phil_function(void *arg)
{
	t_philosopher_info	*info;
	int					left_fork;
	int					right_fork;

	info = (t_philosopher_info *)arg;
	left_fork = info->id;
	right_fork = (left_fork + 1) % info->total_phil;
	gettimeofday(&info->track, NULL);
	gettimeofday(&info->start, NULL);
	while (1)
	{
		if (info->eat_count == info->total_eat)
			return (NULL);
		ft_eat(info, left_fork, right_fork); // check if we can eat
		if (info->eat_flag == 1)
			ft_sleep(info); // sleeping
		else // thinking
			ft_time_stamps(info, 4);
	}
}

/*
*/