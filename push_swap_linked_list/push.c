/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:17:56 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/30 10:24:09 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_index_update(stack_a);
	ft_index_update(stack_b, track);
	ft_printf("pb\n");
}

void	ft_pb(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_index_update_a(stack_a);
	ft_index_update_b(stack_b, track);
	ft_printf("pa\n");
}
