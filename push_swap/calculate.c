/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:55:25 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/21 16:06:18 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calculate_difference(t_list *temp_a, t_list *temp_b)
{
	int	result;

	result = temp_a->value - temp_b->value;
	if (result < 0)
		result *= -1;
	return (result);
}

void	ft_calculate_rotations_a(t_track *track)
{
	if (track->pc_index_a >= track->border_a)
		track->close_tot_op_a = track->size_a - track->pc_index_a;
	else
		track->close_tot_op_a = track->pc_index_a;
}

void	ft_calculate_rotations_b(t_track *track)
{
	track->location = 0;
	if (track->close_val_b > track->close_val_a)
		track->location = 1;
	if (track->pc_index_b >= track->border_b)
	{
		if (track->location == 1)
			track->close_tot_op_b = track->size_b - (track->pc_index_b + 1);
		else
			track->close_tot_op_b = track->size_b - track->pc_index_b;
	}
	else
	{
		if (track->location == 1)
			track->close_tot_op_b = track->pc_index_b + 1;
		else
			track->close_tot_op_b = track->pc_index_b;
	}
}

/*
With notes:


{
	if (track->pc_index_a >= track->border_a) // number is in bottom half
		track->close_tot_op_a = track->size_a - track->pc_index_a;
	else
		track->close_tot_op_a = track->pc_index_a;
}

void	ft_calculate_rotations_b(t_track *track)
{
	track->location = 0;
	if (track->close_val_b > track->close_val_a)
		track->location = 1; // closest to last
	if (track->pc_index_b >= track->border_b) // number in bottom = rrb
	{
		if (track->location == 1) // closest moet naar last index
			track->close_tot_op_b = track->size_b - (track->pc_index_b + 1);
		else // closest is smaller, move to top: rrb until last index + 1
			track->close_tot_op_b = track->size_b - track->pc_index_b;
	}
	else
	{
		if (track->location == 1) // getal is groter dan to be pushed
			track->close_tot_op_b = track->pc_index_b + 1;
		else
			track->close_tot_op_b = track->pc_index_b;
	}
}*/