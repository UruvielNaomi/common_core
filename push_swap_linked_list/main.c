/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:48:41 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/04 16:44:25 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		*temp_stack;

	if (argc < 2)
		return (1);
	temp_stack = ft_initialize_temp_stack(argc, argv);
	if (check_temp_stack(temp_stack, argc - 1) == 0)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a)
		return (-1);
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (-1);
	*stack_a = NULL;
	*stack_b = NULL;
	ft_initialize_list(stack_a, temp_stack, argc - 1);
	free(temp_stack);
	ft_push_swap(stack_a, stack_b, argc - 1);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

/*
no malloc needed for track because it's only used
through a chain of functions within ft_push_swap.

want to use it anywhere else? malloc needed!!
*/