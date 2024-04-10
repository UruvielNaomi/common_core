/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:12:35 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/10 09:57:41 by Naomi            ###   ########.fr       */
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

void	ft_fr(int *t_stack, t_list **stack_a, t_list **stack_b)
{
	free(t_stack);
	free_stack(stack_a);
	free_stack(stack_b);
}

void	ft_fr_t_argv(char **t_argv, char **argv)
{
	int	i;

	i = 0;
	if (t_argv != argv)
	{
		while (t_argv[i])
		{
			free(t_argv[i]);
			i++;
		}
		free(t_argv);
	}
}

void	check_and_free_t_stack(int *t_stack, int argc)
{
	if (ft_check_t_stack(t_stack, argc) == 1)
		free(t_stack);
	else if (ft_check_t_stack(t_stack, argc) == 0)
		exit(0);
}
