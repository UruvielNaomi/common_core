/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_temp_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:21:15 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/05 19:49:58 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				ft_printf("Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}

int	check_min_max(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] > INT_MAX || stack[i] < INT_MIN)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_temp_stack(int *stack, int len)
{
	if (check_doubles(stack, len) == 1)
		return (1);
	if (check_temp_stack(stack, len) == 0)
		return (0);
	else
		return (2);
}
