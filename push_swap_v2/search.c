/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:42:42 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/24 12:21:06 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_search_lowest(t_list **stack, t_track *track)
{
	t_list	*temp;

	temp = *stack;
	ft_index_size_update_b(&temp, track);
	track->lowest_value = temp->value;
	track->lowest_index = temp->index;
	if (track->size_b % 2 == 0)
		track->border_b = track->size_b / 2;
	else
		track->border_b = (track->size_b / 2) + 1;
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

void	ft_move_lowest_down(t_list **stack, t_track *track)
{
	if (track->lowest_index < track->border_b)
	{
		while (track->lowest_index != -1)
		{
			ft_rb(stack, track);
			track->lowest_index--;
		}
	}
	else
	{
		while (track->lowest_index < track->size_b)
		{
			ft_rrb(stack, track);
			track->lowest_index++;
		}
	}
}

void	ft_move_lowest_down_a(t_list **stack, t_track *track)
{
	if (track->lowest_index < track->border_b)
	{
		while (track->lowest_index != -1)
		{
			ft_ra(stack, track);
			track->lowest_index--;
		}
	}
	else
	{
		while (track->lowest_index < track->size_b - 1)
		{
			ft_rra(stack, track);
			track->lowest_index++;
		}
	}
}

void	ft_move_lowest_up(t_list **stack, t_track *track)
{
	if (track->lowest_index < track->border_b)
	{
		while (track->lowest_index != 0)
		{
			ft_ra(stack, track);
			track->lowest_index--;
		}
	}
	else
	{
		while (track->lowest_index != track->size_b)
		{
			ft_rra(stack, track);
			track->lowest_index++;
		}
	}
}
