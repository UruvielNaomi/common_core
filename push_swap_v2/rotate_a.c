/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:05:42 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/21 14:29:34 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_last_a(t_list **stack_a, t_track *track)
{
	while (track->fin_index_a >= 0)
	{
		ft_ra(stack_a, track);
		track->fin_index_a--;
	}
}

void	ft_rotate_to_first_a(t_list **stack_a, t_track *track)
{
	while (track->fin_index_a > 0)
	{
		ft_ra(stack_a, track);
		track->fin_index_a--;
	}
}

void	ft_rrotate_to_last_a(t_list **stack_a, t_track *track)
{
	while (track->fin_index_a < (track->size_a) -1)
	{
		ft_rra(stack_a, track);
		track->fin_index_a++;
	}
}

void	ft_rrotate_to_first_a(t_list **stack_a, t_track *track)
{
	while (track->fin_index_a <= track->size_a)
	{
		ft_rra(stack_a, track);
		track->fin_index_a++;
	}
}
