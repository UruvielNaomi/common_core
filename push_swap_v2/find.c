/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:45:08 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/16 08:53:33 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calculate_rotations_a(t_list *temp_a, t_track *track)
{
	// update the variables/functions regarding the size of stack_a, since we now also need to calculate rotations there.
}

void	ft_calculate_rotations_b(t_list *temp_a, t_track *track)
{
	int	location;
	
	location = 0; 
	if (track->close_value > temp_a->value)
		location = 1; // het getal moet naar de laatste plek
	if (track->close_index > track->border) // number is in the bottom, rrb needed
	{
		if (location == 1) // getal is groter dan to be pushed, rrb until last index
			track->close_tot_op = track->size_b - track->close_index - 1;
		else // getal is kleiner en moet naar de eerste plek, rrb until last index + 1 extra rotatie
			track->close_tot_op = track->size_b - track->close_index;
	}
	else
	{
		if (location == 1) // getal is groter dan to be pushed
			track->close_tot_op = track->close_index + 1;
		else
			track->close_tot_op = track->close_index;
	}
}

int	ft_calculate_difference(t_list *temp_a, t_list *temp_b)
{
	int	result;

	result = temp_a->value - temp_b->value;
	if (result < 0)
		result *= -1;
	return (result);
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
	}
	else
		return;	
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
	// zoek dichtsbijzinde getal in waarde in stack_b
	// sla index op van dat getal. 
	// is het getal groter of kleiner
	// is het getal in de bovenste of onderste helft.
	// bereken aantal rb of ra nodig en sla op.
	// sla waardes op in placeholders.
	// vergelijk placebolders??
	// ga naar volgende 
}
