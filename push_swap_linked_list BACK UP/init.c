/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:52:42 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/05 19:29:49 by Naomi            ###   ########.fr       */
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

int	*ft_initialize_temp_stack(int argc, char **argv)
{
	int	*temp_stack;
	int	i;

	temp_stack = (int *)malloc(sizeof(int) * (argc - 1));
	if (!temp_stack)
		return (NULL);
	i = 0;
	while (i < (argc - 1))
	{
		temp_stack[i] = ft_atoi(argv[i + 1], temp_stack);
		i++;
	}
	return (temp_stack);
}
