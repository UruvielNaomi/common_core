/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:07:48 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/29 10:55:30 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"
# include <time.h>


char	*ft_itoa(int nbr);
char	*ft_strjoin(char *s1, char const *s2);

int		ft_count_digits(int nbr);
int		ft_fill_array(char *array, int nbr, int i);
int		move_patrol(t_game *game);

void	find_starting_position_patrol(t_game *game);
void	patrol_encounter(t_game *game);
void	step_counter_window(t_game *game);
void	update_step_counter_window(t_game *game);

#endif
