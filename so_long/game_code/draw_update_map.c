/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:24:19 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/29 20:29:04 by Naomi            ###   ########.fr       */
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

void	update_player_location(t_game *game, int keycode)
{
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;

	x = game->player_pos.x;
	y = game->player_pos.y;
	prev_x = game->prev_pos.x;
	prev_y = game->prev_pos.y;
	draw_image(game, game->grass_img, prev_x, prev_y);
	draw_image(game, game->grass_img, x, y);
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
