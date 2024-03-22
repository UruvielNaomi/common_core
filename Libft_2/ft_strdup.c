/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:37:43 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/03 16:37:47 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	size;
	size_t	i;

	size = ft_strlen(src) + 1;
	i = 0;
	dest = (char *)malloc(sizeof(char) * size);
	if (dest == NULL)
		return (NULL);
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char	*src;
	char	*duplicate;

	src = "Natural20";
	duplicate = ft_strdup(src);
	// printf("%s\n", duplicate);
	//free(duplicate);
	return (0);
}	
*/

/*
By using while (*src), we are iterating through the characters in src
until the null character is encountered, which indicates the end of the string.
*/