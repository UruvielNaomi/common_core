/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:07:48 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/28 16:48:59 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

typedef struct s_game_bonus
{
	char	*str2;
	char	*str3;
}	t_game_bonus;

char	*ft_itoa(int nbr);
char	*ft_strjoin(char *s1, char const *s2);

int		ft_count_digits(int nbr);
int		ft_fill_array(char *array, int nbr, int i);

void	find_starting_position_patrol(t_game *game);
void	patrol_encounter(t_game *game);
void	step_counter_window(t_game *game, t_game_bonus *game_bonus);
void	update_step_counter_window(t_game *game, t_game_bonus *game_bonus);

#endif
