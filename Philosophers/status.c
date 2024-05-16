/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:21:58 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 10:32:12 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
