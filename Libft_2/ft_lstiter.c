/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:41:10 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/14 11:41:12 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
NOTES:
step 1:	check if lst/f are empty.
step 2: create while loop that runs while lst.
step 3: run the function to adjust content.
step 4: move to the next node.

Parameters
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on
	the list.

Return value
	None

External functs.
	None

Description
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.
*/
