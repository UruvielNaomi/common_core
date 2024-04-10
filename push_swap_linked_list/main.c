/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:48:41 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/10 15:45:34 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_temp(int *temp_stack, int argc)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d", temp_stack[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		*temp_stack;

	if (argc < 2)
		return (1);
	ft_check_numeric(argc, argv);
	temp_stack = ft_initialize_temp_stack(argc, argv);
	//ft_printf("Temp stack after initalizing:\n");
	//print_temp(temp_stack, argc);
	ft_check_errors(temp_stack, argc);
	initialize_stacks(&stack_a, &stack_b, temp_stack);
	ft_initialize_list(stack_a, temp_stack, argc - 1);
	ft_push_swap(stack_a, stack_b, argc - 1);
	ft_free_all(temp_stack, stack_a, stack_b);
	return (0);
}
