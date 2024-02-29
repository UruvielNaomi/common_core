/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:24:19 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/29 11:49:36 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

void	player_direction(t_game *game, int keycode, int	pixel_x, int pixel_y)
{
	if (keycode == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player_img_l, pixel_x, pixel_y);
	}
	if (keycode == 2)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player_img_r, pixel_x, pixel_y);
	}
	if (keycode == 13)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player_img_b, pixel_x, pixel_y);
	}
	if (keycode == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player_img_r, pixel_x, pixel_y);
	}
}

void	update_player_location(t_game *game, int keycode)
{
	int	prev_pix_x;
	int	prev_pix_y;
	int	pixel_x;
	int	pixel_y;

	prev_pix_x = game->prev_pos.y * game->img_width;
	prev_pix_y = game->prev_pos.x * game->img_height;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->grass_img, prev_pix_x, prev_pix_y);
	pixel_x = game->player_pos.y * game->img_width;
	pixel_y = game->player_pos.x * game->img_height;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->grass_img, pixel_x, pixel_y);
	player_direction(game, keycode, pixel_x, pixel_y);
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
