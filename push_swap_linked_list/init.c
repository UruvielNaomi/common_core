/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:52:42 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/10 09:35:10 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialize_list(t_list **stack_a, int *t_stack, int size)
{
	int		i;
	t_list	*new;

	i = 0;
	while (i < size)
	{
		new = ft_lstnew(t_stack[i], i);
		ft_lstadd_back(stack_a, new);
		i++;
	}
}

int	*ft_initialize_t_stack(int argc, char **argv)
{
	int	*t_stack;
	int	i;

	t_stack = (int *)malloc(sizeof(int) * (argc - 1));
	if (!t_stack)
		return (NULL);
	i = 0;
	while (i < (argc - 1))
	{
		t_stack[i] = ft_atoi(argv[i + 1], t_stack);
		i++;
	}
	return (t_stack);
}

void	initialize_stacks(t_list ***stack_a, t_list ***stack_b)
{
	*stack_a = (t_list **)malloc(sizeof(t_list *));
	if (!*stack_a)
		exit(-1);
	*stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!*stack_b)
		exit(-1);
	**stack_a = NULL;
	**stack_b = NULL;
}
