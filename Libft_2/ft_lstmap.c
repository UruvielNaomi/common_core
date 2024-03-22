/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:42:09 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/14 11:42:12 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, (del));
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*
step 1: create an empty new_lst + two pointers (new_node & prev_node)
		to keep track of the newly created nodes.
step 2:	iterate over original list: for every node in list, apply
		function, get new content.
step 3: if function fails, clear the new_lst and return NULL to 
		indicate error.
step 4: if succes (f): new node with new content created by ft_lstnew.
step 5: if ft_lstnew fails, delete new_content, clear new_lst, return NULL.
step 6: if ft_lstnew succeeds: add new_node to end of new_lst
step 7: If new_lst is NULL (first node), set new_lst to the new_node. 
		Otherwise, it sets the next pointer of the previous node prev_node 
		to the new node.
step 8: updates prev_node to new_node, move to next node in the original 
		list (lst).
step 9: after iterating over all nodes: return new_lst.

Parameters
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on
	the list.
	del: The address of the function used to delete
	the content of a node if needed.

Return value
	The new list.
	NULL if the allocation fails.

External functs.
	malloc, free

Description
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node. Creates a new
	list resulting of the successive applications of
	the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.
*/
