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
	return ((char *)str); // we want to return a non const pointer, hence we typecast.
}

char	*ft_strjoin(char *s1, char const *s2)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t s3_len;
	char	*s3;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s3_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * s3_len + 1);
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
	s3 = '\0';
	return (s3);
}

char	*ft_strndup(char *src, size_t n)
{
	char	*dest;
	ssize_t	i;
	ssize_t	length;

	length = ft_strlen(src);
	i = 0;
	if (n < length)
		length = n;
	if (!src)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * length + 1);
	if (!dest)
		return (NULL);
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	ssize_t	i;

	if (!src)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	ssize_t i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}