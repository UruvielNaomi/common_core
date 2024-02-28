/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:54:18 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/28 14:27:49 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"
#include "so_long_bonus.h"

void	update_collectables(t_game *game, int x, int y)
{
	game->collectables -= 1;
	game->player_pos.x = x;
	game->player_pos.y = y;
	game->map[x][y] = '0';
}

int	move_accepted(t_game *game, int x, int y)
{
	game->prev_pos.x = game->player_pos.x;
	game->prev_pos.y = game->player_pos.y;
	if (game->map[x][y] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("Congratulations! You brought all the hats back!");
		close_window(game);
	}
	if (game->map[x][y] == 'C')
		update_collectables(game, x, y);
	if (game->map[x][y] == '0')
	{
		game->player_pos.x = x;
		game->player_pos.y = y;
	}
	if (game->map[x][y] == 'G')
		patrol_encounter(game);
	if (game->collectables == 0)
		update_exit(game);
	return (1);
}
