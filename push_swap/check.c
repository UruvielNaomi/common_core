/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:27:06 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/20 13:45:58 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_array(int *array, int size)
{
	int i;
	
	i = 0;
	while(i < size - 1) // to prevent accessing memory out of the array in our if statement, the last number has already been checked.
	{
		if (array[i] > array[i + 1])
			return (1);
		i++;
	}
	return (0);
}