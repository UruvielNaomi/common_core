/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:29:26 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/01 14:29:28 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while ((n > 0) && (s1[a] != '\0' || s2[a] != '\0'))
	{
		if (s1[a] != s2[a])
			return (((unsigned char)s1[a] - (unsigned char)s2[a]));
		a++;
		n--;
	}
	return (0);
}
/*
int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = "HelloxWorld123";
    size_t n = 6;

    int result_custom = ft_strncmp(str1, str2, n);

    printf("Custom ft_strncmp result: %d\n", result_custom);

    return 0;
}
*/

/*
compare s1 and s2 up to n amount of characters.

Return values:
< 0: first non matching char has a lower ascii value in s1 than s2.
0: strings are equal
> 0: first non matching char has a higher ascii value in s1 than s2.
*/

/*
The if (n == 0) condition is not necessary in this context. 
The while loop already takes care of the scenario where n becomes 0.
*/