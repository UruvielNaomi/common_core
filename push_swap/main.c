/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:48:41 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/27 18:38:14 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_swap(int *stack_a, int len)
{
	if (len == 1)
	{
		ft_printf("No operations needed, array contains only one integer\n");
		return (0);
	}
	if (len == 2)
		ft_check_2(stack_a);
	if (len == 3)
		ft_check_3(stack_a, len);
	if (len > 3)
		ft_insertion(stack_a, len);
	else
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int	*stack_a;
	int	len;
	int	i;	

	if (argc > 1)
	{
		len = argc - 1;			
		stack_a = (int *)malloc(sizeof(int) * len);
		if (!stack_a)
			return (NULL);
		i = 0;
		while (stack_a[i])
		{
			stack_a[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		ft_push_swap(stack_a, len);
		free(stack_a);
	}
	return (0);
}
