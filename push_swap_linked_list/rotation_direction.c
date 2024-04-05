/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_direction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:24:20 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/05 11:28:34 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_last(t_list **stack_b, t_track *track)
{
	while (track->loc_top > 0)
	{
		ft_rb(stack_b);
		track->loc_top--;
	}
}

void	ft_rotate_to_first(t_list **stack_b, t_track *track)
{
	while (track->loc_top > 1)
	{
		ft_rb(stack_b);
		track->loc_top--;
	}
}

void	ft_rrotate_to_last(t_list **stack_b, t_track *track)
{
	while (track->loc_bot < track->size)
	{
		ft_rrb(stack_b);
		track->loc_bot++;
	}
}

void	ft_rrotate_to_first(t_list **stack_b, t_track *track)
{
	while (track->loc_bot < track->size + 1)
	{
		ft_rrb(stack_b);
		track->loc_bot++;
	}
}
