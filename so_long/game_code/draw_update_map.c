/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:24:19 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/13 10:17:06 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

void	player_direction(t_game *game, int keycode, int x, int y)
{
	if (keycode == 0)
		draw_image(game, game->player_img_l, x, y);
	if (keycode == 2)
		draw_image(game, game->player_img_r, x, y);
	if (keycode == 13)
		draw_image(game, game->player_img_b, x, y);
	if (keycode == 1)
		draw_image(game, game->player_img_r, x, y);
}

void	update_player_location(t_game *game, int keycode, int x, int y)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->prev_pos.x;
	prev_y = game->prev_pos.y;
	draw_image(game, game->grass_img, prev_x, prev_y);
	if (game->map[prev_x][prev_y] == 'E')
		draw_image(game, game->exit_closed_img, prev_x, prev_y);
	if (game->map[x][y] == 'C')
	{
		draw_image(game, game->grass_img, x, y);
		game->map[x][y] = '0';
	}
	player_direction(game, keycode, x, y);
}

void	update_exit(t_game *game)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = game->exit_pos.y * game->img_width;
	pixel_y = game->exit_pos.x * game->img_height;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->exit_open_img, pixel_x, pixel_y);
}

void	exit_closed(t_game *game, int keycode, int x, int y)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->prev_pos.x;
	prev_y = game->prev_pos.y;
	draw_image(game, game->grass_img, prev_x, prev_y);
	player_direction(game, keycode, x, y);
}
