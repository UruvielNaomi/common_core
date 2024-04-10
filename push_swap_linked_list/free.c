/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:12:35 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/10 09:23:44 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
	*stack = NULL;
}

void	ft_free_all(int *temp_stack, t_list **stack_a, t_list **stack_b, char **temp_argv)
{
	int i;

	i = 0;
	free(temp_stack);
	free_stack(stack_a);
	free_stack(stack_b);
	while (temp_argv[i]) 
	{
		free(temp_argv[i]);
		i++;
	}
	free(temp_argv);
}

void check_and_free_temp_stack(int *temp_stack, int argc)
{
	if (ft_check_temp_stack(temp_stack, argc) == 1)
		free(temp_stack);
	else if (ft_check_temp_stack(temp_stack, argc) == 0)
		exit(0);
}
