/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:49:46 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/03 12:03:19 by nstacia          ###   ########.fr       */
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
# include <limits.h>

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
	int	lowest_value;
	int	lowest_index;
}	t_track;


int	ft_check_stack_asc(t_list **stack);
int	ft_check_stack_desc(t_list **stack);
int	check_temp_stack(int *stack, int len);
int	*ft_initialize_temp_stack(int argc, char **argv);


void	ft_check_2(t_list **stack_a);
void	ft_check_3(t_list **stack_a);
void	ft_divide_stack_b(t_track *track);
void	ft_equal(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_high_bottom(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_high_top(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_index_update(t_list **stack);
void	ft_index_size_update(t_list **stack, t_track *track);
void	ft_initialize_list(t_list **stack_a, int *temp_stack);
void	ft_insertion(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_organise_stack_b(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_pa(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_pb(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_push_2(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_push_swap(t_list **stack_a, t_list **stack_b, int size);
void	ft_rb(t_list **stack_b);
void	ft_rrb(t_list **stack_b);
void	ft_rotate_to_first(t_list **stack_b, t_track *track);
void	ft_rotate_to_last(t_list **stack_b, t_track *track);
void	ft_rrotate_to_first(t_list **stack_b, t_track *track);
void	ft_rrotate_to_last(t_list **stack_b, t_track *track);
void	ft_sa(t_list **stack_a);
void	ft_search_bottom(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_search_lowest(t_list **stack_b, t_track *track);
void	ft_search_top(t_list **stack_a, t_list **stack_b, t_track *track);
void	free_stack(t_list **stack);


#endif