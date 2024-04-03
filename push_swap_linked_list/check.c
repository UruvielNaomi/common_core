/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:23:14 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/03 09:59:04 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_2(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		ft_sa(stack_a);
		ft_index_update(stack_a);
	}
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
	ft_sa(stack_a);
}

int	ft_check_stack_asc(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_check_stack_desc(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (current->value < current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_temp_stack(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}
