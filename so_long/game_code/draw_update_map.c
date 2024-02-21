/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:24:19 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/21 15:38:58 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_location(t_game *game)
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
		game->player_img, pixel_x, pixel_y);
}

void	update_collectibles(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, x, y);
}
