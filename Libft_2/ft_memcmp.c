/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:15:46 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/01 17:15:47 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if (!s1 && !s2)
		return (0);
	while (len > 0)
	{
		if (*ptr_s1 != *ptr_s2)
			return (*ptr_s1 - *ptr_s2);
		ptr_s1++;
		ptr_s2++;
		len--;
	}
	return (0);
}
/*
int	main(void)
{ 	const char *str1 = "Hello, World!";
    const char *str2 = "Hello, World!";
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Vergelijk met de aangepaste memcmp functie
    int result_ft = ft_memcmp(str1, str2, len1);

    // Vergelijk met de standaard memcmp functie
    int result_st = memcmp(str1, str2, len2);

    if (result_custom == 0)
        printf("Ft_memcmp: Memory is identiek.\n");
    else
        printf("Ft_memcmp: Memory niet identiek (verschil=%d).\n", result_ft);
    if (result_standard == 0)
        printf("Memcmp: Memory is identiek.\n");
    else
        printf("Memcmp: Memory niet identiek (verschil=%d).\n", result_st);
    return 0;
}
*/