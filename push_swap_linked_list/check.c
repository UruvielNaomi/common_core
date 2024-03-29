/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:23:14 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/29 12:39:29 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_2(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_sa(stack_a);
}

void	ft_check_3(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value && \
		((*stack_a)->value > (*stack_a)->next->next->value))
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if ((*stack_a)->value > (*stack_a)->next->value && \
		(*stack_a)->value < (*stack_a)->next->next->value)
		ft_sa(stack_a);
	else if ((*stack_a)->value > (*stack_a)->next->next->value && \
		(*stack_a)->value < (*stack_a)->next->value)
		ft_rra(stack_a);
	else if ((*stack_a)->next->value > (*stack_a)->value && \
		(*stack_a)->next->value > (*stack_a)->next->next->value)
		ft_ra(stack_a);
	else if ((*stack_a)->next->next->value > (*stack_a)->value && \
		(*stack_a)->next->next->value > (*stack_a)->next->value)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
}

int	ft_check_stack(t_list **stack)
{
	t_list *current;
	
	current = *stack;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}
