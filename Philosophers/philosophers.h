/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:15 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 09:47:27 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "ft_printf.h"

typedef struct s_philosopher_info
{
	int				personal_id;
	int				eat_count;
	int				total_philosophers;
	int				sleep_time;
	int				eat_time;
	int				die_time;
	int				total_eat;
	char 			*status;
    pthread_mutex_t	*forks;
}	t_philosopher_info;

////////////// free.c //////////////
void	ft_destroy_mutex(pthread_mutex_t *forks, int total_philosophers);
void	ft_free_all(pthread_t *philosophers, pthread_mutex_t *forks);

////////////// init.c //////////////
void	ft_init_all(char **argv, pthread_t **philosophers, pthread_mutex_t **forks, int total_philosophers);
void	ft_init_forks(pthread_mutex_t **forks, int total_philosophers);


////////////// status.c //////////////
void* philosopher_function(void* arg);

#endif