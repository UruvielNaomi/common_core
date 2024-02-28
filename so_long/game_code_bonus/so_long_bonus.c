/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:40:47 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/28 16:48:51 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line.h"

void	find_starting_position_patrol(t_game *game)
{
	int	i;
	int	j;
	int	found;

	i = game->map_height - 1;
	found = 0;
	while (i >= 0 && !found)
	{
		j = game->map_width - 1;
		while (j >= 0 && !found)
		{
			if (game->map[i][j] == '0')
			{
				game->patrol_pos.y = j;
				game->patrol_pos.x = i;
				game->map[i][j] = 'G';
				found = 1;
			}
			j--;
		}
		i--;
	}
}

void	step_counter_window(t_game *game, t_game_bonus *game_bonus)
{
	char	*str1;
	
	str1 = "Steps: ";
	game_bonus->str2 = ft_itoa(game->count_moves);
	game_bonus->str3 = ft_strjoin(str1, game_bonus->str2);
	mlx_string_put(game->mlx, game->win, game->map_width - (game->map_width / 10),\
	game->map_height - (game->map_height / 10), 0xFFFFFF,  game_bonus->str3);
}

void	update_step_counter_window(t_game *game, t_game_bonus *game_bonus)
{
	char	*str1;
	
	str1 = "Steps: ";

	if (game_bonus->str2)
		free(game_bonus->str2);
	game_bonus->str2 = ft_itoa(game->count_moves);
	if (game_bonus->str3)
		free(game_bonus->str3);
	game_bonus->str3 = ft_strjoin(str1, game_bonus->str2);
}
