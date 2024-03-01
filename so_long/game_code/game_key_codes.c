/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_codes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:38:23 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/01 12:53:23 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

int	move_player_left_right(t_game *game, int keycode)
{
	int	x;
	int	y;
	int	check;

	x = game->player_pos.x;
	y = game->player_pos.y;
	if (keycode == 0)
	{
		y--;
		if (game->map[x][y] == '1')
			return (0);
		check = move_accepted(game, x, y);
	}
	if (keycode == 2)
	{
		y++;
		if (game->map[x][y] == '1')
			return (0);
		check = move_accepted(game, x, y);
	}
	if (check == 1)
		update_player_location(game, keycode, x, y);
	if (check == 2)
		exit_closed(game, keycode, x, y);
	return (1);
}

int	move_player_up_down(t_game *game, int keycode)
{
	int	x;
	int	y;
	int	check;

	x = game->player_pos.x;
	y = game->player_pos.y;
	if (keycode == 13)
	{
		x--;
		if (game->map[x][y] == '1')
			return (0);
		check = move_accepted(game, x, y);
	}
	if (keycode == 1)
	{
		x++;
		if (game->map[x][y] == '1')
			return (0);
		check = move_accepted(game, x, y);
	}
	if (check == 1)
		update_player_location(game, keycode, x, y);
	if (check == 2)
		exit_closed(game, keycode, x, y);
	return (1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
	game->map = NULL;
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	free(game->mlx);
	if (game->str2)
	{
		free(game->str2);
		game->str2 = NULL;
	}
	if (game->str3)
	{
		free(game->str3);
		game->str2 = NULL;
	}
	exit (0);
}

int	key_press(int keycode, t_game *game)
{
	int	move;

	move = 0;
	if (keycode == 53)
		close_window(game);
	else if (keycode == 0)
		move = move_player_left_right(game, keycode);
	else if (keycode == 13)
		move = move_player_up_down(game, keycode);
	else if (keycode == 1)
		move = move_player_up_down(game, keycode);
	else if (keycode == 2)
		move = move_player_left_right(game, keycode);
	if (move == 1)
	{
		game->count_moves++;
		ft_printf("\rTotal moves:  %d  \n", game->count_moves);
		update_step_counter_window(game);
	}
	return (0);
}

/*
    ‘w’: 13 (up)
    ‘s’: 1 (down)
    ‘a’: 0 (left)
    ‘d’: 2 (right)
*/
