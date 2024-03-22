/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:27:17 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/10 15:27:18 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current;

	current = lst;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/*
NOTES ON CODE:
step 1: create an int for counting the nodes.
step 2: create a structure to initialize current node.
step 3: current = first link of the list (later changes to current).
step 4: while current is pointing to a valid node:
step 5: increase count & update the current pointer, 
		to point to the link/next of the new node

Parameters 
	lst: The beginning of the list.

Return value 
	The length of the list

External functs. 
	None

Description
	Counts the number of nodes in a list.
*/