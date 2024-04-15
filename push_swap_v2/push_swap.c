/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:38:25 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/15 13:14:57 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_back(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_index_size_update(stack_b, track);
	while (track->size != 0)
		ft_pa(stack_a, stack_b, track);
}

void	ft_sort_stack(t_list **stack_a, t_list **stack_b, t_track *track)
{
	while ((*stack_a != NULL))
		ft_insert_sort(stack_a, stack_b, track);
	if (ft_check_stack_desc(stack_b) == 1)
	{
		ft_search_lowest(stack_b, track);
		ft_move_lowest_down(stack_b, track);
	}
	while ((*stack_b) != NULL)
		ft_move_back(stack_a, stack_b, track);
}

void	ft_push_2(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_pb(stack_a, stack_b, track);
	ft_pb(stack_a, stack_b, track);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	t_track	track;

	if (size == 1)
		return ;
	if (size == 2)
		ft_check_2(stack_a);
	if (size == 3)
		ft_check_3(stack_a, &track);
	if (size == 4)
		ft_check_4(stack_a, stack_b, &track);
	if (size == 5)
		ft_check_5(stack_a, stack_b, &track);
	if (size > 5)
	{
		ft_push_2(stack_a, stack_b, &track);
		ft_check_2(stack_a);
		ft_sort_stack(stack_a, stack_b, &track);
	}
}

/*
ft_printf("Stack A before:\n");
ft_print_stack(stack_a);

ft_printf("Stack B after:\n");
ft_print_stack(stack_b);
ft_printf("Stack A after:\n");
ft_print_stack(stack_a);

Voor push 2:
//ft_printf("Before ft_push_2:\nStack A: ");
//ft_print_stack(*stack_a);
//ft_printf("Stack B: ");
//ft_print_stack(*stack_b);

Na push 2:
//ft_printf("After ft_push_2:\nStack A: ");
//ft_print_stack(*stack_a);
//ft_printf("Stack B: ");
//ft_print_stack(*stack_b);

Na insertion:
//t_printf("After ft_push_2:\nStack A: ");
//ft_print_stack(*stack_a);
//ft_printf("Stack B: ");
//ft_print_stack(*stack_b);
*/