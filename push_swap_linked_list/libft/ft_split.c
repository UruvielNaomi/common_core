/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:46:30 by nstacia           #+#    #+#             */
/*   Updated: 2024/04/10 17:31:40 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static char	*ft_putword(char *word, char const *s, size_t i, size_t word_len)
{
	size_t	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**split_words(char const *s, char c, char **array, size_t tot_words)
{
	size_t	i;
	size_t	word_len;
	size_t	word;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < tot_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			word_len++;
			i++;
		}
		array[word] = (char *)malloc(sizeof(char) * word_len + 1);
		if (!array[word])
			return (free_array(array, word));
		ft_putword(array[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	array[word] = 0;
	return (array);
}

static size_t	word_total(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**array;
	unsigned int	tot_words;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	if (s[i] == '\0')
	{
		array = malloc(sizeof(char *));
		if (!array)
			return (NULL);
		*array = NULL;
		return (array);
	}
	tot_words = word_total(s, c);
	array = (char **)malloc(sizeof(char *) * (tot_words + 1));
	if (!array)
		return (NULL);
	return (split_words(s, c, array, tot_words));
}

/*
we have two pointers because:
	- the first one we need for the to be made arrays
	- the second one for the delimiter

The array of new strings resulting from the split.
NULL if memory allocation fails or if ‘s’ is NULL.
The last element of the array is set to NULL.

Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.

s: The string to be split.
c: The delimiter character.


if free_array is called its is due to a failed malloc:
	it will be freeing the memory of any previously allocated 
	strings in the array (which are still empty at this point), 
	and then freeing the array itself.
*/