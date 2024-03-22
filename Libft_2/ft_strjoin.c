/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:25:24 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/06 14:25:25 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	s3_len;

	s3_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (s3_len + 1));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < s3_len)
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] && i < s3_len)
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
/*
int	main(void)
{
	const char	*str1 = "Hello, ";
	const char	*str2 = "world!";
	char		*result = ft_strjoin(str1, str2);

	if (result)
	{
		printf("Concatenated string: %s\n", result);
		free(result);
	}
	else
		printf("ft_strjoin returned NULL. Unable to concatenate.\n");
	return (0);
}

Return value The new string.
NULL if the allocation fails

Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.

*/