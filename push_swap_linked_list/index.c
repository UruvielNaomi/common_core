/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:40:25 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/30 09:49:50 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_update_a(t_list **stack_a)
{
	t_list	*temp;
	int		i;

	temp = *stack_a;
	i = 0;
	while (temp != NULL)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}

void	ft_index_update_b(t_list **stack_b, t_track *track)
{
	t_list	*temp;
	int		i;

	temp = *stack_b;
	i = 0;
	while (temp != NULL)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
	track->size = i + 1;
}
