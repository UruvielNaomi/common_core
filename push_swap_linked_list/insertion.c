/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:18:59 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/29 14:53:54 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_position_stack_b(t_list **stack_a, t_list **stack_b)
{
	// prepare order of stack b.
	// stack_b element 1 value must be lower than stack_a element 1.
	// stack_b last_index must be higher than stack_a element 1.
}

void	ft_push_2(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	track->size = 2;
	track->count = 0;
}

void	ft_insertion(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_find_position_stack_b(stack_a, stack_b);
}
