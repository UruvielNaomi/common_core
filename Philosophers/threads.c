/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:17:27 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 16:15:35 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_join_threads(pthread_t **phil, int total_phil)
{
	int	i;

	i = 0;
	while (i < total_phil)
	{
		pthread_join(phil[i], NULL);
		i++;
	}
}
