/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:21:58 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 15:50:41 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	ft_eat(t_philosopher_info *info, int left_fork, int right_fork)
{
	long	elapsed_time;

	pthread_mutex_lock(&info->forks[left_fork]); // pick up left fork
	if (pthread_mutex_lock(&info->forks[right_fork]) != 0)
		pthread_mutex_unlock(&info->forks[left_fork]);
	else 
	{
		gettimeofday(&info->end, NULL); // get the end time
		elapsed_time = calculate_elapsed_time(info->start, info->end);
		if (elapsed_time > info->die_time)
		{
			ft_time_stamps(info, 5);
			return (NULL); // end of function
		}
		gettimeofday(&info->start, NULL);
		usleep(info->eat_time);// eating...
		info->eat_flag = 1;
		pthread_mutex_unlock(&info->forks[right_fork]); // put down right fork
		pthread_mutex_unlock(&info->forks[left_fork]); // put down left fork
		gettimeofday(&info->start, NULL); // reset start time after successful eating
	}
}

void	ft_sleep(t_philosopher_info *info)
{
	ft_time_stamps(info, 3);
	usleep(info->sleep_time);
	info->eat_flag = 0;
	info->eat_count += 1;
}

void* philosopher_function(void* arg) 
{
    t_philosopher_info *info;
    int left_fork;
    int right_fork;
	
	info = (t_philosopher_info*)arg;
	left_fork = info->personal_id;
    right_fork = (left_fork + 1) % info->total_philosophers;
	gettimeofday(&info->track, NULL);
	gettimeofday(&info->start, NULL);
	while (1) 
	{
		if (info->eat_count == info->total_eat)
			return (NULL);
		ft_eat(info, left_fork, right_fork); // eating
		if (info->eat_flag == 1)
			ft_sleep(info); // sleeping
		else // thinking
			ft_time_stamps(info, 4);
	}
}

/*
void* philosopher_function(void* arg) 
{
    t_philosopher_info *info;
    int left_fork;
    int right_fork;
	int	eat_flag;
	
	info = (t_philosopher_info*)arg;
	eat_flag = 0;
	int left_fork = info->personal_id;
    int right_fork = (left_fork + 1) % info->total_philosophers;
	while (1) 
	{
		pthread_mutex_lock(&info->forks[left_fork]); // pick up left fork
		if (pthread_mutex_lock(&info->forks[right_fork]) != 0)
			pthread_mutex_unlock(&info->forks[left_fork]);
		else 
		{
			usleep(info->eat_time);// eating...
			eat_flag = 1;
			pthread_mutex_unlock(&info->forks[right_fork]); // put down right fork
			pthread_mutex_unlock(&info->forks[left_fork]); // put down left fork
		}
		if (eat_flag == 1)
		{
			usleep(info->sleep_time);
			eat_flag = 0;
			info->eat_count += 1;
		}
	}
}
*/