/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:18:37 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/10 09:33:12 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str, int *t_stack);
void	ft_lstadd_back(t_list **lst, t_list *new);
size_t	ft_strlen(const char *str);
t_list	*ft_lstnew(int value, int index);

#endif