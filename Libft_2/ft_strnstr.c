/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:51:52 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/03 12:51:53 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && !len)
		return (0);
	if (needle[0] == '\0' || needle == haystack)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (haystack[i + j] == '\0' && needle[j] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}

/*
What:
	locate a substring in a string. full substr needs to be found

Return value:
	a pointer to the start of where needle is found in haystack.

syntax:
	char *strnstr(const char *haystack, const char *needle, size_t len);

(needle == haystack)
	checks if *needle and *haystack point to the same memory address. 

two times if (needle[j] == '\0'):
	The second if condition is necessary because it’s possible that 
	haystack has not reached its null terminator, but a full match 
	of needle has been found in haystack.
*/