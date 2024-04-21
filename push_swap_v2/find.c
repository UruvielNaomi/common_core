/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:45:08 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/21 15:33:30 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_fastest(t_track *track)
{
	ft_calculate_rotations_a(track);
	ft_calculate_rotations_b(track);
	track->close_tot_op = track->close_tot_op_a + track->close_tot_op_b + 1;
	if (track->close_tot_op < track->least_tot_op)
	{
		track->fin_index_a = track->pc_index_a;
		track->fin_index_b = track->pc_index_b;
		track->fin_location = track->location;
		track->least_tot_op = track->close_tot_op;
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
	//track->least_tot_op = 1;
	track->fin_location = 0;
	ft_printf("test\n");
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
			ft_printf("closest value a = %d\n", track->close_val_a);
			ft_printf("closest index a = %d\n", track->pc_index_a);
			ft_printf("closest value b = %d\n", track->close_val_b);
			ft_printf("closest index b = %d\n\n", track->pc_index_b);
			ft_find_fastest(track);
			ft_printf("final closest index a = %d\n", track->fin_index_a);
			ft_printf("final closest index b = %d\n", track->fin_index_b);
			temp_a = temp_a->next;
		}
	}
}

/*

Voor poging optimaliseren:

void	ft_calculate_rotations_a(t_list *temp_a, t_track *track)
{
	if (temp_a->index > track->border_a) // number is in bottom half
		track->close_tot_op_a = track->size_a - temp_a->index;
	else
		track->close_tot_op_a = temp_a->index;	
}

void	ft_calculate_rotations_b(t_list *temp_a, t_track *track)
{
	int	location;
	
	location = 0; 
	if (temp_b->valuetrack->close_value > temp_a->value)
		location = 1; // het getal moet naar de laatste plek
	if (track->close_index > track->border_b) // number is in the bottom, rrb needed
	{
		if (location == 1) // getal is groter dan to be pushed, rrb until last index
			track->close_tot_op_b = track->size_b - track->close_index - 1;
		else // getal is kleiner en moet naar de eerste plek, rrb until last index + 1 extra rotatie
			track->close_tot_op_b = track->size_b - track->close_index;
	}
	else
	{
		if (location == 1) // getal is groter dan to be pushed
			track->close_tot_op_b = track->close_index + 1;
		else
			track->close_tot_op_b = track->close_index;
	}
}

void	ft_find_closest(t_list *temp_a, t_list *temp_b, t_track *track)
{
	if (ft_calculate_difference(temp_a, temp_b) < track->close_dif)
	{
		track->close_value = temp_b->value;
		track->close_index = temp_b->index;
		track->close_dif = ft_calculate_difference(temp_a, temp_b);
		ft_calculate_rotations_b(temp_a, track);
		ft_calculate_rotations_a(temp_a, track);
		track->close_tot_op = track->close_tot_op_a + track->close_tot_op_b;
		if (!track->least_tot_op)
				track->least_tot_op = track->close_tot_op;
		if (track->close_tot_op < track->least_tot_op)
		{
			track->pc_index_a = temp_a->index; // location a
			track->pc_index_b = temp_b->index; // location b
		}
	}
	else
		return;	
}
int	ft_calculate_difference(t_list *temp_a, t_list *temp_b)
{
	int	result;

	result = temp_a->value - temp_b->value;
	if (result < 0)
		result *= -1;
	return (result);
}

void	ft_find_location(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = (*stack_a);
	temp_b = (*stack_b);
	track->close_value = temp_b->value;
	track->close_index = temp_b->index;
	track->close_dif = ft_calculate_difference(temp_a, temp_b);
	temp_b = temp_b->next;
	while (temp_a != NULL)
	{
		while (temp_b != NULL)
		{
			ft_find_closest(temp_a, temp_b, track);
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
}
ft_printf("value stack a: %d\n", temp_a->value);
ft_printf("value stack b: %d\n", temp_b->value);
ft_printf("index stack a: %d\n", temp_a->index);
ft_printf("index stack b: %d\n", temp_b->index);
ft_printf("operations stack a: %d\n", track->close_tot_op_a);
ft_printf("operations stack b: %d\n", track->close_tot_op_b);
ft_printf("close tot op: %d\n", track->close_tot_op);
ft_printf("least tot op: %d\n\n", track->least_tot_op);
ft_printf("least tot op if updated: %d\n\n", track->least_tot_op);
*/