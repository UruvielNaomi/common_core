/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:57:37 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 16:13:37 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	int				total_phil;
	pthread_t		*phil;
	pthread_mutex_t	*forks;

	total_phil = ft_atoi(argv[1]);
	ft_init_all(**argv, phil, forks, total_phil);
	ft_destroy_mutex(forks, total_phil);
	ft_free_all(phil, forks);
	return (0);
}
