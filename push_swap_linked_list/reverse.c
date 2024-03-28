/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:08:48 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/28 14:33:25 by Naomi            ###   ########.fr       */
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
	temp->next = NULL; // Set temp->next to NULL to avoid circling since it will be the last element.
	ft_lstadd_back(stack_b, temp);
}

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
	temp_back->next = *stack_b; // the last node becomes the first node
	*stack_b = temp_back; // update the head of the list
}

