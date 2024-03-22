/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:23:44 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/07 14:23:45 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(char const c, char const *s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	trim_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_check(s1[i], set) == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static size_t	trim_end(char const *s1, char const *set, size_t start)
{
	size_t	size;

	size = ft_strlen(s1 + start);
	while (size != 0)
	{
		if (ft_check(s1[start + size - 1], set) == 1)
			size--;
		else
			break ;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copystr;
	size_t	start;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	start = trim_start(s1, set);
	size = trim_end(s1, set, start);
	copystr = (char *)malloc(sizeof(char) * size + 1);
	if (!copystr)
		return (NULL);
	ft_strlcpy(copystr, s1 + start, size + 1);
	return (copystr);
}

/*
s1: The string to be trimmed.
set: The reference set of characters to trim.

Return value 
	If memory allocation is successful and the resulting trimmed 
	string is not empty, a pointer to the trimmed string is returned.
	If s1 or set is NULL, or if memory allocation fails, or if the 
	resulting trimmed string is empty, NULL is returned.

External functs. malloc

Description 
	Allocates (with malloc(3)) and returns a copy of
	’s1’ with the characters specified in ’set’ removed
	from the beginning and the end of the string.

NOTES:
	needed helper functions:
	reminder: in trim_end start = [i].
	size = ft_strlen(s1 + start) --> the start moves the pointer to
	the start of the string and it will calculate the size from there).

	if (ft_check(s1[start + size - 1], set) == 1)
		basically says (s1[i + size - 1]).
		i = start of the string after trimming start.
		-1 because we need to align size with index.
*/