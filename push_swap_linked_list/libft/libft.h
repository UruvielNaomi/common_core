/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:18:37 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/03 13:20:17 by nstacia          ###   ########.fr       */
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

int	ft_atoi(const char *str);

void	ft_lstadd_back(t_list **lst, t_list *new);

size_t	ft_strlen(const char *str);

t_list	*ft_lstnew(int value, int index);

#endif