/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:24:19 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/28 13:49:33 by Naomi            ###   ########.fr       */
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
		game->grass_img, pixel_x, pixel_y);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->player_img_r, pixel_x, pixel_y);
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
void	patrol_encounter(t_game *game)
{
	ft_printf("G A M E   O V E R !");
	close_window(game);
}
