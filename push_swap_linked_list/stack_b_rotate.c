/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:24:20 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/04 14:28:05 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_last(t_list **stack_b, t_track *track)
{
	while (track->close_top != 0)
	{
		ft_rb(stack_b);
		track->close_top--;
	}
}

void	ft_rotate_to_first(t_list **stack_b, t_track *track)
{
	while (track->close_top != 1)
	{
		ft_rb(stack_b);
		track->close_top--;
	}
}

void	ft_rrotate_to_last(t_list **stack_b, t_track *track)
{
	while (track->close_bot != track->size)
	{
		ft_rrb(stack_b);
		track->close_bot++;
	}
}

void	ft_rrotate_to_first(t_list **stack_b, t_track *track)
{
	while (track->close_bot != track->size + 1)
	{
		ft_rrb(stack_b);
		track->close_bot++;
	}
}

/*
comments:

void	ft_rotate_to_last(t_list **stack_a, t_list **stack_b, t_track *track)
{
	while (track->close_top != 0) // 0 because the first element is 1, so making it go to zero will rotate one time extra so its the last element.
	{
		ft_rb(stack_b);
		track->close_top--;
	}
}

void	ft_rrotate_to_last(t_list **stack_a, t_list **stack_b, t_track *track)
{
	while (track->close_bot != track->size + 1) // opposite of != 0. size is the last element, therefore one step furthers means it will rotate one time extra, pushing it to the top.
	{
		ft_rrb(stack_b);
		track->close_bot--;
	}
}

*/