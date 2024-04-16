/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:51:01 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/16 11:38:58 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_last_b(t_list **stack_b, t_track *track)
{
	while (track->pc_index_b > 0)
	{
		ft_rb(stack_b, track);
		track->pc_index_b--;
	}
}

void	ft_rotate_to_first_b(t_list **stack_b, t_track *track)
{
	while (track->pc_index_b > 1)
	{
		ft_rb(stack_b, track);
		track->pc_index_b--;
	}
}

void	ft_rrotate_to_last_b(t_list **stack_b, t_track *track)
{
	while (track->pc_index_b < track->size_b)
	{
		ft_rrb(stack_b, track);
		track->pc_index_b++;
	}
}

void	ft_rrotate_to_first_b(t_list **stack_b, t_track *track)
{
	while (track->pc_index_b < track->size_b + 1)
	{
		ft_rrb(stack_b, track);
		track->pc_index_b++;
	}
}
