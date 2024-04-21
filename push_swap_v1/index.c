/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:40:25 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/18 13:58:12 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_update(t_list **stack)
{
	t_list	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp != NULL)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}

void	ft_index_size_update_b(t_list **stack, t_track *track)
{
	t_list	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp != NULL)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
	track->size = i;
}
