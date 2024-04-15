/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:15:31 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/15 14:37:36 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insert_sort(t_list **stack_a, t_list **stack_b, t_track *track)
{
	if (track->size % 2 == 0)
		track->border = track->size / 2;
	else
		track->border = (track->size / 2) + 1;
	ft_find_fastest(stack_a, stack_b, track);
}
