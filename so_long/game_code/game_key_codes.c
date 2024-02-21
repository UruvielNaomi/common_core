/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_codes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:38:23 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/21 15:34:48 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player_left_right(t_game *game, int keycode)
{
	int	x;
	int	y;

	x = game->player_pos.x;
	y = game->player_pos.y;
	if (keycode == 0)
	{
		y--;
		if (game->map[x][y] == '1')
			return (0);
		move_accepted(game, x, y);
	}
	if (keycode == 2)
	{
		y++;
		if (game->map[x][y] == '1')
			return (0);
		move_accepted(game, x, y);
	}
	update_player_location(game);
	return (1);
}

int	move_player_up_down(t_game *game, int keycode)
{
	int	x;
	int	y;

	x = game->player_pos.x;
	y = game->player_pos.y;
	if (keycode == 13)
		x--;
	if (keycode == 2)
		x++;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		free_map(game);
		close_window(game);
		exit(0);
	}
	else if (keycode == 0)
		move_player_left_right(game, keycode);
	else if (keycode == 13)
		move_player_up_down(game, keycode);
	else if (keycode == 1)
		move_player_up_down(game, keycode);
	else if (keycode == 2)
		move_player_left_right(game, keycode);
	return (0);
}
