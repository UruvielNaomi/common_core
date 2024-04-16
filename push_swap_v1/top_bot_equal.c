/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_bot_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:52:05 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/16 08:53:33 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_closest_top(t_list **stack_a, t_list **stack_b, t_track *track)
{
	if (track->topval_top > (*stack_a)->value)
		ft_rotate_to_last(stack_b, track);
	else
		ft_rotate_to_first(stack_b, track);
}

void	ft_closest_bottom(t_list **stack_a, t_list **stack_b, t_track *track)
{
	if (track->topval_bot > (*stack_a)->value)
		ft_rrotate_to_last(stack_b, track);
	else
		ft_rrotate_to_first(stack_b, track);
}

void	ft_equal(t_list **stack_a, t_list **stack_b, t_track *track)
{
	if (track->size_b % 2 == 0)
	{
		if (track->topval_top > (*stack_a)->value)
			ft_rotate_to_last(stack_b, track);
		else
			ft_rotate_to_first(stack_b, track);
	}
	else
	{
		if (track->loc_top < (track->size_b - track->loc_bot + 1))
		{
			if (track->topval_top > (*stack_a)->value)
				ft_rotate_to_last(stack_b, track);
			else
				ft_rotate_to_first(stack_b, track);
		}
		else
		{
			if (track->topval_bot > (*stack_a)->value)
				ft_rrotate_to_last(stack_b, track);
			else
				ft_rrotate_to_first(stack_b, track);
		}
	}
}