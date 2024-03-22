/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:58:55 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/10 14:58:56 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
NOTES ON CODE:
step 1: check if either the head pointer or the new node is NULL.
step 2: Set the next pointer of the new node to the current head of the list.
step 3: Update the head pointer to point to the new node.

Parameters
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be added to the list.

Return value 
	None

Description
	Adds the node ’new’ at the beginning of the list.
	The ft_lstadd_front function is designed to add new node to the 
	front (or the beginning) of an existing linked list. The new node 
	becomes the new head of the list, and its next pointer is set to 
	point to the original head of the list. This way, the new node is 
	effectively inserted at the front of the list, and it becomes the 
	first element in the linked list.

	The ft_lstadd_front function doesn't need to use malloc because it 
	assumes that the new node (t_list *new) has already been allocated 
	memory elsewhere before calling this function.
*/