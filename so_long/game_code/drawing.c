/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:35:25 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/19 19:07:44 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void images_to_window(t_game *game)
{
    int x = game->player_pos.x * game->player_width;  // Multiply by the width of a tile
    int y = game->player_pos.y * game->player_height; // Multiply by the height of a tile
    mlx_put_image_to_window(game->mlx, game->win, game->player_img, x, y);
}


void load_images(t_game *game) 
{
    game->player_width = 32;
    game->player_height = 32;
    game->player_img = mlx_xpm_file_to_image(game->mlx, "../images/player_cat.xpm", &game->player_width, &game->player_height);
}


/*
void	ft_xpm_to_image(t_game game)
{
	
	// int bits_per_pixel;
	// int line_length;
	// int endian;
	
	int x;
	int y;

	game.img = mlx_xpm_file_to_image(game.mlx, "filename", x, y);
	// game.addr = mlx_get_data_addr(game.img, &bits_per_pixel, &line_length, &endian);
}

void	ft_image_to_window(t_game game)
{
	int x;
	int y;

	mlx_put_image_to_window(game.mlx, game.win, game.img, x, y);
}
*/