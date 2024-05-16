/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stamps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:18:47 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 16:15:42 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_time_stamps(t_philosopher_info *info, int stamp_nr)
{
	struct timeval	now;
	long			time_stamp;

	gettimeofday(&now, NULL);
	time_stamp = calculate_elapsed_time(info->track, now);
	if (stamp_nr == 1)
		printf("%ld, %d has taken a fork\n", time_stamp, info->nr);
	if (stamp_nr == 2)
		printf("%ld, %d is eating\n", time_stamp, info->nr);
	if (stamp_nr == 3)
		printf("%ld, %d is sleeping\n", time_stamp, info->nr);
	if (stamp_nr == 4)
		printf("%ld, %d is thinking\n", time_stamp, info->nr);
	if (stamp_nr == 5)
		printf("%ld, %d died\n", time_stamp, info->nr);
}
