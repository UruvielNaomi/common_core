/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:45:24 by Naomi             #+#    #+#             */
/*   Updated: 2024/05/16 16:10:59 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	calculate_elapsed_time(struct timeval start, struct timeval end)
{
	long	sec_diff;
	long	mic_sec_diff;
	long	elapsed_mil_sec;

	sec_diff = end.tv_sec - start.tv_sec;
	mic_sec_diff = end.tv_usec - start.tv_usec;
	elapsed_mil_sec = (sec_diff * 1000) + (mic_sec_diff / 1000);
	return (elapsed_mil_sec);
}
