/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:18:59 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/30 13:39:41 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// search top and bottom half of stack_b for value closest to stack_a[0]
void	ft_search_top(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp;
	int		i;

	temp = *stack_b;
	i = 1;
	track->dif_top = (*stack_a)->value - temp->value;
	while (i <= track->j)
	{
		temp = temp->next;
		if ((*stack_a)->value - temp->value < track->dif_top)
		{
			track->dif_top = (*stack_a)->value - temp->value;
			track->close_top = i;
		}
		i++;
	}
}

void	ft_search_bottom(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp;
	int		i;

	temp = *stack_b;
	while (i <= track->j)
		temp = temp->next;
	track->dif_bot = (*stack_a)->value - temp->value;
	while (i <= track->k)
	{
		temp = temp->next;
		if ((*stack_a)->value - temp->value < track->dif_bot)
		{
			track->dif_bot = (*stack_a)->value - temp->value;
			track->close_bot = i;
		}
		i++;
	}
}

void	ft_divide_stack_b(t_track *track)
{
	if (track->size % 2 == 0)
	{
		track->j = track->size / 2;
		track->k = track->size / 2;
	}
	else
	{
		track->j = track->size / 2;
		track->k = track->size / 2 + 1;
	}
}

void	ft_organise_stack_b(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp;

	temp = *stack_b;
	ft_divide_stack_b(track);
	ft_search_top(stack_a, stack_b, track);
	ft_search_bottom(stack_a, stack_b, track);
	if (track->close_top < (track->close_bot - track->size)) // is the closest number found in the top, closer to the top than the closest found number in the bottom, to the bottom?
	{
		if (temp->value > (*stack_a)->value)
			ft_rb(stack_b);
		
	}
		// if yes, check if value is higher or lower than stack_a->value.
			// if its higher, rotate b: shift up all elements of stack b by 1: The first element becomes the last one-->call function ft_rb until this element has been placed at the bottom of stack_b.
			// if its lower, check if it is at the top already, if not rotate b until its placed at the top of stack_b.
		// if no, closest number found is in the bottom part:
			// is the found number higher than the to be pushed one, check if its the first element reverse rotate: shift down all elements of stack b by 1: The last element becomes the first one.--> call function ft_rrb until the found element has been placed at the bottom of stack_b.
			// if its lower, reverse rotate until its placed at the top of stack_b.
	// if top and bottom have equally close numbers
}

// prepare order of stack b.
// stack_b element 1 value must be lower than stack_a element 1.
// stack_b last_index must be higher than stack_a element 1.

/*
t_list	*temp;

	temp = stack_b;
	if ((*stack_a)->value > temp->value)
	{
		while (temp->next != NULL)
			temp = temp->next;
		if ((*stack_a)->value < temp->value)
			ft_pb(stack_a, stack_b, track);
	}
*/