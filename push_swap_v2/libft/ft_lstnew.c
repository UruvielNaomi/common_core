/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:58:36 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/28 12:06:04 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int value, int index)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

/*

Parameters 
	content: The content to create the node with.

Return value
	The new node.

External functs. 
	malloc

Description
	Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with
	the value of the parameter ’content’. 
	The variable ’next’ is initialized to NULL.


Notes:
	Head: the first pointer of a list, points to the first node.
	in linked the nodes dont have to be sequentially stored (memory addres),
	they are linked.
*/