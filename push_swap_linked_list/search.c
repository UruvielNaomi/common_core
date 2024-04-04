/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:42:42 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/04 16:55:43 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_search_lowest(t_list **stack, t_track *track)
{
	t_list	*temp;

	temp = *stack;
	track->lowest_value = temp->value;
	track->lowest_index = temp->index;
	ft_index_size_update(&temp, track);
	if (track->size % 2 == 0)
		track->border = track->size / 2;
	else
		track->border = track->size / 2 + 1;
	while (temp != NULL)
	{
		if (temp->value < track->lowest_value)
		{
			track->lowest_value = temp->value;
			track->lowest_index = temp->index;
		}
		temp = temp->next;
	}
}

void	ft_move_lowest_down(t_list **stack, t_track *track) // stack b
{
	if (track->lowest_index < track->border)
	{
		while (track->lowest_index != -1)
		{
			ft_rb(stack);
			track->lowest_index--;
		}
	}		
	else
		while (track->lowest_index < track->size)
		{
			ft_rrb(stack);
			track->lowest_index++;
		}		
}

void	ft_move_lowest_up(t_list **stack, t_track *track) //stack_a
{
	if (track->lowest_index < track->border)
	{
		while (track->lowest_index != 0)
		{
			ft_ra(stack);
			track->lowest_index--;
		}
	}		
	else
		while (track->lowest_index != track->size)
		{
			ft_rra(stack);
			track->lowest_index++;
		}		
}