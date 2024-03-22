/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:31:00 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/10 16:31:01 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

/*
step 1: create new structure to keep track of last node in the s_list.
step 2: check if new and/or lst are empty, if yes: failed-->return NULL.
step 3: check if just !lst is empty, if yes, make this node the new (last) node.
step 4: find the last node in the list.
step 5: Add the new node to the back of the list.

why not using *lst, why create *last?
	This would actually modify the original head pointer, and by the end 
	of the loop, *lst would point to the last node in the list. 
	The problem with this is that the original head pointer would now 
	be pointing to the last node, and the list would effectively be 
	truncated.
*/