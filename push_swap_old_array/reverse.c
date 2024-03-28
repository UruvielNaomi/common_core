/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:14:55 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/28 09:42:43 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(int *stack_b, int len)
{
	int	temp;
	int i;

	temp = stack_b[0];
	i = 0;
	while (i < len - 2)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[len - 1] = temp;
}

void	ft_rrb(int *stack_b, int len)
{
	int	temp;
	int i;

	temp = stack_b[len - 1];
	i = len - 1;
	while (i >= 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
}
