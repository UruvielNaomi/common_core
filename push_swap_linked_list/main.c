/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:48:41 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/10 09:22:31 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		*temp_stack;
	char	**temp_argv;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		temp_argv = ft_split(argv[1], ' ');
		argc = 0;
		while (temp_argv[argc])
			argc++;
	}
	else
		temp_argv = argv;
	ft_check_numeric(argc, temp_argv);
	temp_stack = ft_initialize_temp_stack(argc, temp_argv);
	check_and_free_temp_stack(temp_stack, argc);
	initialize_stacks(&stack_a, &stack_b);
	ft_initialize_list(stack_a, temp_stack, argc - 1);
	ft_push_swap(stack_a, stack_b, argc - 1);
	ft_free_all(temp_stack, stack_a, stack_b, temp_argv);
	return (0);
}


// to do: error displays.

/*
no malloc needed for track because it's only used
through a chain of functions within ft_push_swap.

want to use it anywhere else? malloc needed!!
*/