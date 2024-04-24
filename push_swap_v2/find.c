/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:45:08 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/24 12:21:34 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_fastest(t_track *track)
{
	ft_calculate_rotations_a(track);
	ft_calculate_rotations_b(track);
	track->close_tot_op = track->close_tot_op_a + track->close_tot_op_b;
	if (track->close_tot_op <= track->least_tot_op)
	{
		track->fin_index_a = track->pc_index_a;
		track->fin_index_b = track->pc_index_b;
		track->fin_location = track->location;
		track->least_tot_op = track->close_tot_op;
		track->op_count_b = track->close_tot_op_b;
	}
}

void	ft_find_closest(t_list *temp_a, t_list *temp_b, t_track *track)
{
	track->close_dif = ft_calculate_difference(temp_a, temp_b);
	track->close_val_a = temp_a->value;
	track->close_val_b = temp_b->value;
	track->pc_index_a = temp_a->index;
	track->pc_index_b = temp_b->index;
}

void	ft_push_top(t_list **stack_a, t_list **stack_b, t_track *track)
{
	track->fin_index_a = (*stack_a)->index;
	track->fin_index_b = (*stack_b)->index;
	track->fin_location = 0;
}

void	ft_find_location(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = (*stack_a);
	temp_b = (*stack_b);
	track->least_tot_op = INT_MAX;
	if (ft_check_stack_0(temp_b, temp_a) == 0 && temp_a->value < temp_b->value)
		ft_push_top(stack_a, stack_b, track);
	else
	{
		while (temp_a != NULL)
		{
			temp_b = (*stack_b);
			track->close_dif = ft_calculate_difference(temp_a, temp_b);
			while (temp_b != NULL)
			{
				if (ft_calculate_difference(temp_a, temp_b) <= track->close_dif)
					ft_find_closest(temp_a, temp_b, track);
				temp_b = temp_b->next;
			}
			ft_find_fastest(track);
			temp_a = temp_a->next;
		}
	}
}
