/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:15:31 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/21 15:54:45 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **stack_a, t_track *track)
{
	if (track->fin_index_a >= track->border_a) // number is in the bottom
		ft_rrotate_to_first_a(stack_a, track);
	else
		ft_rotate_to_first_a(stack_a, track);
}

void	ft_rotate_b(t_list **stack_b, t_track *track)
{
	if (track->fin_index_b >= track->border_b) // number is in the bottom
	{
		if (track->fin_location == 1) // closest needs to be at bottom of stack_b
			ft_rrotate_to_last_b(stack_b, track);
		else
			ft_rrotate_to_first_b(stack_b, track);
	}
	else
	{
		if (track->fin_location == 1)
			ft_rotate_to_last_b(stack_b, track);
		else
			ft_rotate_to_first_b(stack_b, track);
	}
}

void	ft_action(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_rotate_a(stack_a, track);
	ft_rotate_b(stack_b, track);
	ft_pb(stack_a, stack_b, track);
}

void	ft_calculate_borders(t_track *track)
{
	if (track->size_b % 2 == 0)
		track->border_b = track->size_b / 2;
	else
		track->border_b = (track->size_b / 2) + 1;
	if (track->size_a % 2 == 0)
		track->border_a = track->size_a / 2;
	else
		track->border_a = (track->size_a / 2) + 1;
}

void	ft_insert_sort(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_calculate_borders(track);
	ft_find_location(stack_a, stack_b, track);
	ft_action(stack_a, stack_b, track);
}
