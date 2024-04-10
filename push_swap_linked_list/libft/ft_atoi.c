/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:18:10 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/10 13:22:19 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_min_max_error(int *temp_stack)
{
	printf("Error\n");
	free(temp_stack);
	exit(1);
}

int	ft_atoi(const char *str, int *temp_stack)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result == 214748364 && (str[i] == '8' || str[i] == '9')) || \
			(result > 214748364))
			ft_int_min_max_error(temp_stack);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
