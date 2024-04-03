/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:08:48 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/03 13:20:33 by nstacia          ###   ########.fr       */
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
	ft_index_update(stack_b);
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
	ft_index_update(stack_b);
	*stack_b = temp_back;
	ft_printf("rrb\n");
}

void	ft_ra(t_list **stack_a)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	ft_lstadd_back(stack_a, temp);
	ft_index_update(stack_a);
	ft_printf("ra\n");
}

void	ft_rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp_back;
	t_list	*prev;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	temp_back = temp;
	prev->next = NULL;
	temp_back->next = *stack_a;
	ft_index_update(stack_a);
	*stack_a = temp_back;
	ft_printf("rra\n");
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