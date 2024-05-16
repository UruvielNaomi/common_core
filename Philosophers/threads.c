/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:17:27 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 10:20:20 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_join_threads(pthread_t **philosophers, int total_philosophers)
{
	int i;

	i = 0;
	while (i < total_philosophers)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}
}