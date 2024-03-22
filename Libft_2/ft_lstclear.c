/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:40:22 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/14 11:40:24 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

/*
step 1: create 2 structures. tmp to look at the current node.
		next to move to the next.
step 2: check if lst and dell are empty, in that case return.
step 3: make temp point to the first node.
step 4: while we have nodes loop.
step 5: next = temp->next; save the next node before freeing.
step 6: delete the content of current node.
step 7: free current node.
step 8: move to the next node.
step 9: set list pointer to NULL.

Parameters
	lst: The address of a pointer to a node.
	del: The address of the function used to delete
	the content of the node.

Return
	value None

External functs.
	free

Description
	Deletes and frees the given node and every
	successor of that node, using the function ’del’
	and free(3).
	Finally, the pointer to the list must be set to
	NULL.
*/
