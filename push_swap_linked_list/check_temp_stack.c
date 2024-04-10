/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_temp_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:21:15 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/10 15:59:35 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_temp_stack(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	check_doubles(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] == stack[j])
			{
				ft_printf("Error: doubles\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_errors(int *temp_stack, int argc)
{
	if (check_doubles(temp_stack, argc - 1) == 1)
	{
		free(temp_stack);
		exit (1);
	}
	if (check_temp_stack(temp_stack, argc - 1) == 0)
	{
		free(temp_stack);
		exit (0);
	}
}

void	ft_check_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				ft_printf("Error, not numeric\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}
