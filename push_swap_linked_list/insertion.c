/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:18:59 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/30 10:38:54 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_position_stack_b(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp;

	temp = stack_b;
	if ((*stack_a)->value > temp->value)
	{
		while (temp->next != NULL)
			temp = temp->next;
		if ((*stack_a)->value < temp->value)
			ft_pb(stack_a, stack_b, track);
	}
	else
		ft_decide_rotate(stack_a, stack_b, track);
	// prepare order of stack b.
	// stack_b element 1 value must be lower than stack_a element 1.
	// stack_b last_index must be higher than stack_a element 1.
}
