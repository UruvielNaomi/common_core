/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:51:54 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/29 12:25:28 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line.h"

int	ft_fill_array(char *array, int nbr, int i)
{
	char	*numbers;

	numbers = "0123456789";
	if (nbr < 0)
	{
		array[i] = '-';
		nbr *= -1;
		i++;
	}
	if (nbr >= 10)
	{
		i = ft_fill_array(array, nbr / 10, i);
		nbr %= 10;
	}
	if (nbr < 10)
	{
		array[i] = numbers[nbr % 10];
		i++;
	}
	return (i);
}

int	ft_count_digits(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += 1;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*array;
	int		length;
	int		i;

	i = 0;
	length = ft_count_digits(nbr);
	array = (char *)malloc(sizeof(char) * length + 1);
	if (!array)
		return (NULL);
	i = ft_fill_array(array, nbr, i);
	array[i] = '\0';
	return (array);
}
