/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:49:46 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/28 11:44:36 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

// Stack

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;


#endif