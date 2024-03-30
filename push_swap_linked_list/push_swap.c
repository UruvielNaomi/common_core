/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:38:25 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/30 12:51:50 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion(t_list **stack_a, t_list **stack_b, t_track *track)
{
	while ((*stack_a != NULL))
		ft_organise_stack_b(stack_a, stack_b, track);
	while ((*stack_b) != NULL)
		ft_pa(stack_a, stack_b, track);
}

void	ft_push_2(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_pb(stack_a, stack_b, track);
	ft_pb(stack_a, stack_b, track);
	track->count = 0; // needed??
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	t_track	track;

	if (size == 1)
		return ;
	if (size == 2)
		ft_check_2(stack_a);
	if (size == 3)
		ft_check_3(stack_a);
	if (size > 3)
	{
		ft_push_2(stack_a, stack_b, &track);
		ft_insertion(stack_a, stack_b, &track);
	}
}