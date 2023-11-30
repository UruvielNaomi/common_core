#include "get_next_line.h"

int	ft_strlen(const char *string)
{
	int a;

	a = 0;
	while (string && string[a]) // to prevent seg faults we need to check if the string is a valid pointer (is it pointing to something in the memory), if so, then check if string[a] contains a character that is not '\0'
		a++; // count how many characters
	return (a);
}

char	*ft_strchr(const char *string, int a)
{
	if (!string) //if there is no string, we cant do shit
		return (NULL); // so return NULL
	while (*string != (char)a) // typecast int to char
	{
		if (*string == '\0')
			return (NULL); // not found
		string++;
	}
	return ((char *)string); // typecast it because we get a const char, which we cant modify, so we need to typecast it to a char.
}

char	*ft_strndup(char *src, int a)
{

}
// use malloc

char	*ft_strdup(char *src)
{

}
// use malloc

char	*ft_strjoin(char *s1, char const *s2)
{
	/*
	variables needed: s1, s2, s3, s3_length, i, j;
	check before: do s1/s2 have content? if not: make it an empty string. 
	1. strlen to calculate the new length.
	2. malloc to allocate memory for new string.
	3. first we put s1 in s3.
	4. then we add s2 to s3.
	*/
	char	*s3;
	size_t	s3_length;
	size_t	i;
	size_t	j;

	s3_length = strlen(s1) + strlen(s2);
	i = 0;
	j = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s3 = (char *)malloc(sizeof(char) * s3_length + 1);
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return(s3);
}
// use malloc
