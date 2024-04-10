/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:48:41 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/10 10:53:29 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		*t_stack;
	char	**t_argv;

	if (argc < 2)
		return (1);
	//if (argc == 2)
	//	t_argv = ft_split(argv[1], ' ');
	//else
	t_argv = argv;
	ft_check_numeric(argc, t_argv);
	t_stack = ft_initialize_t_stack(argc, t_argv);
	check_and_free_t_stack(t_stack, argc);
	initialize_stacks(&stack_a, &stack_b);
	ft_initialize_list(stack_a, t_stack, argc - 1);
	ft_push_swap(stack_a, stack_b, argc - 1);
	ft_fr(t_stack, stack_a, stack_b);
	ft_fr_t_argv(t_argv, argv);
	return (0);
}

// to do: error displays.

/*
no malloc needed for track because it's only used
through a chain of functions within ft_push_swap.

want to use it anywhere else? malloc needed!!
*/