/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:13:25 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/10 16:13:29 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
NOTES ON CODE:
step 1: check if lst is empty, if yes return NULL.
step 2: create while loop that continues as long as the next pointer of 
		the current node (lst->next) is not NULL
step 3: lst = lest-> // move to the next node.
step 4: return the last node.

Parameters 
	lst: The beginning of the list.

Return value 
	Last node of the list

Description 
	Returns the last node of the list.
*/