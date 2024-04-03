/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organise_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:52:05 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/30 15:21:29 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_high_top(t_list **stack_a, t_list **stack_b, t_track *track)
{

}

void	ft_high_bottom(t_list **stack_a, t_list **stack_b, t_track *track)
{

}

void	ft_equal(t_list **stack_a, t_list **stack_b, t_track *track)
{
	if (track->size % 2 == 0)
	{
		if (track->value_top > (*stack_a)->value)
			ft_rotate_to_last(stack_a, stack_b, track);
		else
			ft_rotate_to_first(stack_a, stack_b, track);
	}
	else
	{
		if (track->close_top < (track->size - track->close_bot))
		{
			if (track->value_top > (*stack_a)->value)
				ft_rotate_to_last(stack_a, stack_b, track);
			else
				ft_rotate_to_first(stack_a, stack_b, track);
		}
		else
		{
			if (track->value_bot > (*stack_a)->value)
				ft_rrotate_to_last(stack_a, stack_b, track);
			else
				ft_rrotate_to_first(stack_a, stack_b, track);
		}
	}
}

/*
with comments:

void	ft_equal(t_list **stack_a, t_list **stack_b, t_track *track)
{
	if (track->size % 2 == 0) // even numbers, so nb of operations is the same
	{
		if (track->value_top > (*stack_a)->value) // found number is higher
			ft_rotate_to_last(stack_a, stack_b, track);
		else
			ft_rotate_to_first(stack_a, stack_b, track);
	}
	else // uneven numbers
	{
		if (track->close_top < (track->size - track->close_bot)) // is the closest number found in the top, closer to the top than the closest found number in the bottom, to the bottom? close->bot has the location of the element, so to see how far it is from the bottom, we deduct that location from the total size, to see how many steps it is to the bottom.
		{
			if (track->value_top > (*stack_a)->value) // found number higher?
				ft_rotate_to_last(stack_a, stack_b, track);
			else
				ft_rotate_to_first(stack_a, stack_b, track);
		}
		else // closest number closer to the bottom
		{
			if (track->value_bot > (*stack_a)->value) // found number higher?
				ft_rrotate_to_last(stack_a, stack_b, track);
			else
				ft_rrotate_to_first(stack_a, stack_b, track);
		}
	}
}

*/