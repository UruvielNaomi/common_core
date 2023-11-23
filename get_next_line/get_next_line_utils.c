/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:48:02 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/23 17:54:03 by nstacia          ###   ########.fr       */
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
	dest = (char *)malloc(sizeof(char) * ft_strnlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (*src)
		dest[a++] = *src++;
	dest[a] = '\0';
	return (dest);
}

