/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:39:51 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 16:13:05 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_destroy_mutex(pthread_mutex_t *forks, int total_phil)
{
	int	i;

	i = 0;
	while (i < total_phil)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	ft_free_all(pthread_t *phil, pthread_mutex_t *forks)
{
	free(phil);
	free(forks);
}
