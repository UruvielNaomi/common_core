/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:49:46 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/30 15:04:28 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// Stack

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

// keep track of count and index

typedef struct s_track
{
	int	size;
	int	j;
	int	k;
	int	dif_top;
	int	dif_bot;
	int	close_top;
	int	close_bot;
	int	value_top;
	int	value_bot;
}	t_track;

#endif