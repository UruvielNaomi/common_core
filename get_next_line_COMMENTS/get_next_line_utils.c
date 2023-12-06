#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	s3_len;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s3_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (s3_len + 1));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		a;

	a = 0;
	if (!src)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (*src)
		dest[a++] = *src++;
	dest[a] = '\0';
	return (dest);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	length;
	size_t	i;

	length = ft_strlen(src);
	i = 0;
	if (n < length)
		length = n;
	dest = (char *)malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[length] = '\0';
	return (dest);
}

int	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str && str[a])
		a++;
	return (a);
}
/* 
By checking str && str[a], if str is NULL, the loop won't be executed, 
and the function will return 0. If str points to a valid string, it will 
calculate and return the length of that string.

if we just do while (str[a]), and the string is not valid, 
it wont find a null terminator. which can mess with the loop.
*/