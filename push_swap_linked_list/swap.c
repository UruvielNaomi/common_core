/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:33:16 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/29 12:39:38 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(t_list **stack_a)
{
	t_list *temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a; // hold first element
	*stack_a = (*stack_a)->next;  // move head to the second element
	if ((*stack_a)->next != NULL) // check if there is a third element
	{
		temp->next = (*stack_a)->next; // set pointer of original head to the third element (inserting it therefore between the new 1st and now 3rd.)
		(*stack_a)->next->index = 2;
	}
	else // if there is no third element
		temp->next = NULL;	//set pointer to null to indicate end of the list
	temp->index = 1;
	(*stack_a)->next = temp; // set pointer of new head to temp, the second element.
	(*stack_a)->index = 0;
	ft_printf("sa\n");
}
