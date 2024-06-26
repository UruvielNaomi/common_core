/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_low.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:39:38 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/16 11:40:26 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_2(t_list **stack_a, t_track *track)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		ft_sa(stack_a);
		ft_index_update_a(stack_a, track);
	}
}

void	ft_check_3(t_list **stack_a, t_track *track)
{
	if (ft_check_stack_desc(stack_a) == 0)
	{
		ft_sa(stack_a);
		ft_rra(stack_a, track);
		return ;
	}
	ft_search_lowest(stack_a, track);
	if (track->lowest_index == 1 && \
		(*stack_a)->value < (*stack_a)->next->next->value)
		ft_sa(stack_a);
	else if (track->lowest_index == 2 && \
		(*stack_a)->value < (*stack_a)->next->value)
		ft_rra(stack_a, track);
	else if (track->lowest_index == 1 && \
		(*stack_a)->value > (*stack_a)->next->next->value)
		ft_ra(stack_a, track);
	else
	{
		ft_sa(stack_a);
		ft_ra(stack_a, track);
	}
}

void	ft_check_4(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_search_lowest(stack_a, track);
	ft_move_lowest_up(stack_a, track);
	ft_pb(stack_a, stack_b, track);
	ft_check_3(stack_a, track);
	ft_pa(stack_a, stack_b, track);
}

void	ft_check_5(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_search_lowest(stack_a, track);
	ft_move_lowest_up(stack_a, track);
	ft_pb(stack_a, stack_b, track);
	ft_check_4(stack_a, stack_b, track);
	ft_pa(stack_a, stack_b, track);
}

/*
ft_printf("Stack A after first pb:\n");
	ft_print_stack(stack_a);
	ft_printf("Stack B after first pb:\n");
	ft_print_stack(stack_b);
	ft_printf("\n");
*/