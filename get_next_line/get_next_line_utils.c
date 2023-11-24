/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:48:02 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/24 11:28:36 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

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

int	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		a;

	a = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (*src)
		dest[a++] = *src++;
	dest[a] = '\0';
	return (dest);
}
char *ft_strndup(const char *src, size_t n)
{
    char *dest;
    size_t length;
	size_t i;
	
	length = ft_strlen(src);
	i = 0;
    if (n < length)
        length = n;
    dest = (char *)malloc(sizeof(char) * (length + 1));
    if (dest == NULL)
        return NULL;
   while (i < length) 
   {
		dest[i] = src[i];
    	i++;
	}
    dest[length] = '\0';
    return (dest);
}