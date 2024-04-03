/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:40:25 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/03 10:12:55 by nstacia          ###   ########.fr       */
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

void	ft_index_size_update(t_list **stack, t_track *track)
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
	track->size = i + 1;
}
