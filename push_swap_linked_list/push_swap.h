/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:49:46 by Naomi             #+#    #+#             */
/*   Updated: 2024/04/15 08:35:42 by Naomi            ###   ########.fr       */
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
	int	loc_top;
	int	loc_bot;
	int	topval_top;
	int	topval_bot;
	int	lowest_value;
	int	lowest_index;
	int	border;
}	t_track;

int		check_doubles(int *stack, int len);
int		check_temp_stack(int *stack, int len);
int		ft_check_stack_asc(t_list **stack);
int		ft_check_stack_desc(t_list **stack);
int		*ft_initialize_temp_stack(int argc, char **argv);

void	ft_check_2(t_list **stack_a);
void	ft_check_3(t_list **stack_a, t_track *track);
void	ft_check_4(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_check_5(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_check_numeric(int argc, char **argv);
void	ft_closest_bottom(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_closest_top(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_divide_stack_b(t_track *track);
void	ft_equal(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_check_errors(int *temp_stack, int argc);
void	ft_free_all(int *temp_stack, t_list **stack_a, t_list **stack_b);
void	ft_free_array(char **array, char *str);
void	ft_index_update(t_list **stack);
void	ft_index_size_update(t_list **stack, t_track *track);
void	ft_initialize_list(t_list **stack_a, int *temp_stack, int size);
void	ft_insertion(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_move_back(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_move_lowest_down(t_list **stack, t_track *track);
void	ft_move_lowest_down_a(t_list **stack, t_track *track);
void	ft_move_lowest_up(t_list **stack, t_track *track);
void	ft_organise_stack_b(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_pa(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_pb(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_print_stack(t_list **stack);
void	ft_push_2(t_list **stack_a, t_list **stack_b, t_track *track);
void	ft_push_swap(t_list **stack_a, t_list **stack_b, int size);
void	ft_ra(t_list **stack_a);
void	ft_rra(t_list **stack_a);
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
void	initialize_stacks(t_list ***stack_a, t_list ***stack_b, int *temp_stack);

t_list	**initialize_stack(void);

#endif