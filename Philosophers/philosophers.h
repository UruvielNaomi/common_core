/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:15 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 16:19:50 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include "ft_printf.h"

typedef struct s_philosopher_info
{
	int				id;
	int				nr;
	int				eat_count;
	int				eat_flag;
	int				eat_time;
	int				die_time;
	int				sleep_time;
	int				total_phil;
	int				total_eat;
	pthread_mutex_t	*forks;
	struct timeval	track;
	struct timeval	start;
	struct timeval	end;
}	t_philosopher_info;

////////////// calculate_time.c //////////////
long	calculate_elapsed_time(struct timeval start, struct timeval end);

////////////// free.c //////////////
void	ft_destroy_mutex(pthread_mutex_t *forks, int total_phil);
void	ft_free_all(pthread_t *phil, pthread_mutex_t *forks);

////////////// init.c //////////////
void	ft_init_all(char **argv, pthread_t **phil, \
	pthread_mutex_t **forks, int total_phil);
void	ft_init_forks(pthread_mutex_t **forks, int total_phil);

////////////// status.c //////////////
void	*phil_function(void *arg);

////////////// threads.c //////////////
void	ft_join_threads(pthread_t **phil, int total_phil);

////////////// time_stamps.c //////////////
void	ft_time_stamps(t_philosopher_info *info, int stamp_nr);

#endif