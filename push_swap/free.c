/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:12:35 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/15 08:35:10 by Naomi            ###   ########.fr       */
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

void	ft_free_all(int *temp_stack, t_list **stack_a, t_list **stack_b)
{
	free(temp_stack);
	free_stack(stack_a);
	free_stack(stack_b);
}

void	ft_free_array(char **array, char *str)
{
	int	i;

	i = 0;
	free(str);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
