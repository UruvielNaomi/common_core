/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:48:41 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/28 12:55:38 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 1)
	{
		ft_printf("No operations needed, array contains only one integer\n");
		return (0);
	}
	if (size == 2)
		ft_check_2(stack_a);
	if (size == 3)
		ft_check_3(stack_a);
	if (size > 3)
		ft_insertion(stack_a, size);
}

void	ft_initialize_list(t_list **stack_a, int *temp_stack)
{
   int i;
   t_list	*new;

   i = 0;
   while (temp_stack[i])
   {
	new = ft_lstnew(temp_stack[i], i);
	ft_lstadd_back(stack_a, new);
	i++;
   }
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
	t_list **stack_a;
	t_list **stack_b;
	int *temp_stack;
	
	if (argc < 2)
		return (1);
	temp_stack = ft_create_temp_stack(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list*));
	if (!stack_a)
		return (-1);
	stack_b = (t_list **)malloc(sizeof(t_list*));
	if (!stack_b)
		return (-1);
	*stack_a = NULL;
	*stack_b = NULL;
	ft_initialize_list(stack_a, temp_stack);
	free(temp_stack);
	ft_push_swap(stack_a, stack_b, argc - 1);
	// free nodes!
	free(stack_a);
	free(stack_b);	
	return (0);
}
