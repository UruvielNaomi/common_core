/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_patrol_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:48:56 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/29 10:47:30 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	patrol_direction(t_game *game, int direction, int pixel_x, int pixel_y)
{
	if (direction == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->patrol_img_l, pixel_x, pixel_y);
	}
	if (direction == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->patrol_img_r, pixel_x, pixel_y);
	}
	if (direction == 2)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->patrol_img_b, pixel_x, pixel_y);
	}
	if (direction == 3)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->patrol_img_r, pixel_x, pixel_y);
	}
}

void	update_patrol_location(t_game *game, int direction)
{
	int	prev_pix_x;
	int	prev_pix_y;
	int	pixel_x;
	int	pixel_y;

	prev_pix_x = game->pat_prev_pos.y * game->img_width;
	prev_pix_y = game->pat_prev_pos.x * game->img_height;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->grass_img, prev_pix_x, prev_pix_y);
	pixel_x = game->patrol_pos.y * game->img_width;
	pixel_y = game->patrol_pos.x * game->img_height;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->grass_img, pixel_x, pixel_y);
	patrol_direction(game, direction, pixel_x, pixel_y);
}

int	is_valid_path_patrol(t_game *game, int x, int y)
{
	if (game->map[x][y] == '0')
		return (1);
	else
		return (0);
}

t_point	calculate_direction_patrol(t_game *game, int direction)
{
	t_point new_pos;

	new_pos.x = game->patrol_pos.x;
	new_pos.y = game->patrol_pos.y;
	if (direction == 0)
		new_pos.y -= 1;
	else if (direction == 1)
		new_pos.y += 1;
	else if (direction == 2)
		new_pos.x -= 1;
	else if (direction == 3)
		new_pos.x += 1;
	return (new_pos);
}

int	move_patrol(t_game *game)
{
	int direction;
	t_point new_pos;

	direction = rand() % 4;
	new_pos = calculate_direction_patrol(game, direction);
	if (is_valid_path_patrol(game, new_pos.x, new_pos.y) == 1)
	{
		game->pat_prev_pos.x = game->patrol_pos.x;
		game->pat_prev_pos.y = game->patrol_pos.y;
		game->patrol_pos.x = new_pos.x;
		game->patrol_pos.y = new_pos.y;
		update_patrol_location(game, direction);
	}
	return (0);
}

