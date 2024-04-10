/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:52:42 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/10 15:58:19 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialize_list(t_list **stack_a, int *temp_stack, int size)
{
	int		i;
	t_list	*new;

	i = 0;
	while (i < size)
	{
		new = ft_lstnew(temp_stack[i], i);
		ft_lstadd_back(stack_a, new);
		i++;
	}
}

t_list	**initialize_stack(void)
{
	t_list	**stack;

	stack = (t_list **)malloc(sizeof(t_list *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	return (stack);
}

void	initialize_stacks(t_list ***stack_a, t_list ***stack_b, int *temp_stack)
{
	*stack_a = initialize_stack();
	if (!*stack_a)
	{
		ft_printf("Error\n");
		exit(1);
	}
	*stack_b = initialize_stack();
	if (!*stack_b)
	{
		free(*stack_a);
		free(temp_stack);
		ft_printf("Error\n");
		exit(1);
	}
}

int	*ft_initialize_temp_stack(int argc, char **argv)
{
	int	*temp_stack;
	int	i;
	int	len;

	len = argc - 1;
	temp_stack = (int *)malloc(sizeof(int) * len);
	if (!temp_stack)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp_stack[i] = ft_atoi(argv[i + 1], temp_stack);
		i++;
	}
	return (temp_stack);
}
