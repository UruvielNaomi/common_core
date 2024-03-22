/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:58:27 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/03 16:58:29 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_len;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr_len = ft_strlen(s + start);
	if (len < substr_len)
		size = len + 1;
	else
		size = substr_len + 1;
	substr = (char *)malloc(sizeof(char) * size);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, size);
	return (substr);
}

/*
It returns NULL if the input string s is NULL.

It returns an empty string if the start position is greater than or 
equal to the length of the string.

It allocates memory based on the smaller of len and the length of 
the substring starting from start.

It uses the function ft_strlcpy to copy the string, which is more efficient 
than manually copying each character.

It returns a pointer to the newly allocated substring. 
If memory allocation fails, it returns NULL.
*/