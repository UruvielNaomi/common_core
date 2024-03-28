/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:48:41 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/28 11:13:14 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_initialize_list(t_stack **stack_a, int len, int *temp_stack)
{
   
    return ;
}

int	*ft_create_temp_stack(int argc, char **argv)
{
	int	*temp_stack;
	int	i;
	
	temp_stack = (int *)malloc(sizeof(int) * (argc - 1));
	if (!temp_stack)
		return (NULL);
	i = 0;
	while (i < (argc - 1))
	{
		temp_stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (temp_stack);
}

int main(int argc, char **argv)
{
	t_stack **stack_a;
	t_stack **stack_b;
	int *temp_stack;
	

	if (argc > 1)
	{		
		temp_stack = ft_create_temp_stack(argc, argv);
		stack_a = (t_stack **)malloc(sizeof(t_stack*));
		if (!stack_a)
			return (-1);
		stack_b = (t_stack **)malloc(sizeof(t_stack*));
		if (!stack_b)
			return (-1);
		*stack_a = NULL;
		*stack_b = NULL;
		ft_initialize_list(stack_a, argc - 1, temp_stack);
		free(temp_stack);
	}
	free(stack_a);
	free(stack_b);
	return (0);
}
