/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:48:42 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/10 16:48:43 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}

/*
NOTES:
step 1: check if either the pointer to the node or deletion function pointer
		is empty. if yes, return ;
step 2: then call the delete function on the content on the current node.
step 3: free the memory of that current node.
step 4: set the current node to NULL.

Parameters 
	lst: The node to free.
	del: The address of the function used to delete the content.

Return value 
	None

External functs.
	free

Description:
	Takes as a parameter a node and frees the memory of
	the node’s content using the function ’del’ given
	as a parameter and free the node. The memory of
	’next’ must not be freed.

*/
