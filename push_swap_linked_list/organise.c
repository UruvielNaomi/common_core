/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:18:59 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/04 21:21:48 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calculate_difference(t_list **stack_a, t_list *temp)
{
	int	result;

	result = (*stack_a)->value - temp->value;
	if (result < 0)
		result *= -1;
	return (result);
}

void	ft_search_top(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list *temp;
	int i;

	i = 1;
	temp = *stack_b;
	track->dif_top = ft_calculate_difference(stack_a, temp);
	track->close_top = i;
	track->value_top = temp->value;
	while (i <= track->j)
	{
		if (ft_calculate_difference(stack_a, temp) < track->dif_top)
		{
			track->dif_top = ft_calculate_difference(stack_a, temp);
			track->value_top = temp->value;
		}
		temp = temp->next;
		track->close_top = i;
		i++;
	}
	//ft_printf("Found number top: %d\n", track->value_top);
	//ft_printf("Difference: %d\n", track->dif_top);
	//ft_printf("Location: %d\n", track->close_top);
}
void	ft_search_bottom(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list *temp;
	int i;

	i = 1;
	temp = *stack_b;
	while (i <= track->j)
	{
		temp =temp->next;
		i++;		
	}
	track->dif_bot = ft_calculate_difference(stack_a, temp);
	track->close_bot = i;
	track->value_bot = temp->value;
	while (track->k != 0 && temp != NULL)
	{
		if (ft_calculate_difference(stack_a, temp) < track->dif_bot)
		{
			track->dif_bot = ft_calculate_difference(stack_a, temp);
			track->value_bot= temp->value;
		}
		temp = temp->next;
		track->close_bot = i;
		i++;
		track->k--;
	}
	//ft_printf("Found number bottom: %d\n", track->value_bot);
	//ft_printf("Difference: %d\n", track->dif_bot);
	//ft_printf("Location: %d\n", track->close_bot);
}

void	ft_divide_stack_b(t_track *track)
{
	if (track->size % 2 == 0)
	{
		track->j = track->size / 2;
		track->k = track->size / 2;
	}
	else
	{
		track->j = track->size / 2;
		track->k = track->size / 2 + 1;
	}
}

void	ft_organise_stack_b(t_list **stack_a, t_list **stack_b, t_track *track)
{
	if (*stack_a == NULL)
		return;
	ft_divide_stack_b(track);
	//ft_printf("To be pushed: %d\n", (*stack_a)->value);
	//ft_printf("Size top: %d\n", track->j);
	//ft_printf("Size bottom: %d\n", track->k);
	ft_search_top(stack_a, stack_b, track);
	ft_search_bottom(stack_a, stack_b, track);
	if (track->dif_top < track->dif_bot)
		ft_high_top(stack_a, stack_b, track);
	if (track->dif_bot < track->dif_top)
		ft_high_bottom(stack_a, stack_b, track);
	if (track->dif_bot == track->dif_top)
		ft_equal(stack_a, stack_b, track);
	ft_pb(stack_a, stack_b, track);
}

void	ft_move_back(t_list **stack_a, t_list **stack_b, t_track *track)
{
	ft_index_size_update(stack_b, track);
	while (track->size != 0)
		ft_pa(stack_a, stack_b, track);
}


/*
local problem log:
- size top and bottom halfs = correct.
- 
*/

/*
	ft_printf("dif top:%d\n", track->dif_top);
	ft_printf("number top:%d\n", track->value_top);
	ft_printf("location top:%d\n", track->close_top);
	ft_printf("Found value in bottom:%d\n", track->value_bot);
	ft_printf("Difference in value between stack_a[0] and found number in bottom:%d\n", track->dif_bot);
	ft_printf("Location, spot: %d\n", track->close_bot);
	ft_printf("Total size stack b: %d\n", track->size);

*/
// prepare order of stack b.
// stack_b element 1 value must be lower than stack_a element 1.
// stack_b last_index must be higher than stack_a element 1.