/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:23:14 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/21 15:32:42 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stack_asc(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current != NULL && current->next != NULL)
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
	while (current != NULL && current->next != NULL)
	{
		if (current->value < current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_check_stack_0(t_list *temp_b, t_list *temp_a)
{
	t_list	*current;

	current = temp_b;
	while (current != NULL && current->next != NULL)
	{
		if (current->value < current->next->value)
			return (1);
		current = current->next;
	}
	if (current->value < temp_a->value)
		return (1);
	return (0);
}
