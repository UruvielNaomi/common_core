/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:15:31 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/16 09:51:38 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_action(t_list **stack_a, t_list **stack_b, t_track *track)
{

}

void	ft_calculate_borders(t_track *track)
{
	if (track->size_b % 2 == 0)
		track->border_b = track->size_b / 2;
	else
		track->border_b = (track->size_b / 2) + 1;
	if (track->size_a % 2 == 0)
		track->border_a = track->size_a / 2;
	else
		track->border_a = (track->size_a / 2) + 1;
}

void	ft_insert_sort(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_calculate_borders(track);
	ft_find_fastest(stack_a, stack_b, track);
	ft_action(stack_a, stack_b, track);
}
