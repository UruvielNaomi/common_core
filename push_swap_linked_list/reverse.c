/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:08:48 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/29 14:06:29 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	ft_lstadd_back(stack_b, temp);
	ft_printf("rb\n");
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp_back;
	t_list	*prev;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	temp_back = temp;
	prev->next = NULL;
	temp_back->next = *stack_b;
	*stack_b = temp_back;
	ft_printf("rrb\n");
}

/*
with comments:

void	ft_rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp_back;
	t_list	*prev;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b; // preserve the original head of the list
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	temp_back = temp; // the last node
	prev->next = NULL;
	temp_back->next = *stack_b; // last node becomes first node
	*stack_b = temp_back; // update the head of the list
	ft_printf("rrb\n");
}
*/