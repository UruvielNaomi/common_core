/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:48:41 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/15 09:12:39 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_digits(char **split_str)
{
	int	i;

	i = 0;
	while (split_str[i])
		i++;
	return (i);
}

void	handle_more_args(int argc, char **argv, int **temp_stack)
{
	ft_check_numeric(argc, argv);
	*temp_stack = ft_initialize_temp_stack(argc, argv);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		*temp_stack;
	char	**array;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		argv[1] = ft_strjoin("push_swap ", argv[1]);
		array = ft_split(argv[1], ' ');
		argc = count_digits(array);
		ft_check_numeric(argc, array);
		temp_stack = ft_initialize_temp_stack(argc, array);
		ft_free_array(array, argv[1]);
	}
	else
		handle_more_args(argc, argv, &temp_stack);
	ft_check_errors(temp_stack, argc);
	init_stacks(&stack_a, &stack_b, temp_stack);
	ft_initialize_list(stack_a, temp_stack, argc - 1);
	ft_push_swap(stack_a, stack_b, argc - 1);
	ft_free_all(temp_stack, stack_a, stack_b);
	return (0);
}

/*
void	ft_print_str(char **split_str)
{
	int i = 0;

	while (split_str[i])
	{
		ft_printf("%s\n", split_str[i]);
		i++;
	}
}

void	print_temp_stack(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		ft_printf("%d\n", stack[i]);
		i++;
	}
}

*/
