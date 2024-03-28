/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:27:06 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/28 08:59:56 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_2(int *stack_a)
{
	if (stack_a[0] > stack_a[1])
	{
		ft_sa(stack_a);
		ft_printf("sa\n"); // here or move to function?
	}
	else
		ft_printf("No operations needed, array is sorted\n");
}

void	ft_check_3(int *stack_a)
{
	if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2]) // descending order
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2]) // 1st = largest
		ft_sa(stack_a);
	else if (stack_a[0] > stack_a[2] && stack_a[0] < stack_a[1]) // 1st = second largest
		ft_rra(stack_a);
	else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2]) // 2nd = largest
		ft_ra(stack_a);
	else if (stack_a[0] < stack_a[2] && stack_a[2] < stack_a[1]) // 3rd = largest
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else // already in ascending order
		ft_printf("No operations needed, array is sorted\n");
}

int	check_stack(int *stack, int len)
{
	int i;
	
	i = 0;
	while(i < len - 1) // to prevent accessing memory out of the stack in our if statement, the last number has already been checked.
	{
		if (stack[i] > stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}
