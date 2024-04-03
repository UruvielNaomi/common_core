/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:38:25 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/03 10:46:58 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion(t_list **stack_a, t_list **stack_b, t_track *track)
{
	while ((*stack_a != NULL))
		ft_organise_stack_b(stack_a, stack_b, track);
	if (ft_check_stack_desc(stack_b) == 1)
		ft_search_lowest(stack_b, track);
	while ((*stack_b) != NULL)
		ft_pa(stack_a, stack_b, track);
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
		ft_check_3(stack_a);
	if (size > 3)
	{
		ft_push_2(stack_a, stack_b, &track);
		ft_insertion(stack_a, stack_b, &track);
	}
}
