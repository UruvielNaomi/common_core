/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:45:08 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/16 10:22:58 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calculate_rotations_a(t_list *temp_a, t_track *track)
{
	if (temp_a->index > track->border_a) // number is in bottom half
		track->close_tot_op_a = track->size_a - temp_a->index;
	else
		track->close_tot_op_a = temp_a->index;	
}

void	ft_calculate_rotations_b(t_list *temp_a, t_list *temp_b, t_track *track)
{
	track->location = 0; 
	if (temp_b->value > temp_a->value)
		track->location = 1; // het getal moet naar de laatste plek
	if (temp_b->index > track->border_b) // number is in the bottom, rrb needed
	{
		if (track->location == 1) // getal is groter dan to be pushed, rrb until last index
			track->close_tot_op_b = track->size_b - temp_b->index - 1;
		else // getal is kleiner en moet naar de eerste plek, rrb until last index + 1 extra rotatie
			track->close_tot_op_b = track->size_b - temp_b->index;
	}
	else
	{
		if (track->location == 1) // getal is groter dan to be pushed
			track->close_tot_op_b = temp_b->index + 1;
		else
			track->close_tot_op_b = temp_b->index;
	}
}

void	ft_find_closest(t_list *temp_a, t_list *temp_b, t_track *track)
{
	if (ft_calculate_difference(temp_a, temp_b) < track->close_dif)
	{
		track->close_dif = ft_calculate_difference(temp_a, temp_b);
		ft_calculate_rotations_b(temp_a, temp_b, track);
		ft_calculate_rotations_a(temp_a, track);
		track->close_tot_op = track->close_tot_op_a + track->close_tot_op_b;
		if (!track->least_tot_op)
				track->least_tot_op = track->close_tot_op;
		if (track->close_tot_op < track->least_tot_op)
		{
			track->pc_index_a = temp_a->index; // location a
			track->pc_index_b = temp_b->index; // location b
			track->fin_location = track->location;
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

void	ft_find_fastest(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = (*stack_a);
	temp_b = (*stack_b);
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

void	ft_find_fastest(t_list **stack_a, t_list **stack_b, t_track *track)
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

*/