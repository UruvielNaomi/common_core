/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:35:25 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/21 12:31:33 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_location(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player_img, x, y);
}

void	update_collectibles(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, x, y);	
}
void ft_images_to_window(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->rows)
	{
		y = 0;
		while (game->map[x][y] && game->map[x][y] != '\n')
		{
			int pixel_x = x * game->img_width;
			int pixel_y = y * game->img_height;
			if (game->map[x][y] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, pixel_x, pixel_y);
			if (game->map[x][y] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->grass_img, pixel_x, pixel_y);
			if (game->map[x][y] == 'P')
				update_player_location(game, pixel_x, pixel_y);
			if (game->map[x][y] == 'C')
				update_collectibles(game, pixel_x, pixel_y);
			if (game->map[x][y] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_closed_img, pixel_x, pixel_y);
			y++;
		}
		x++;
	}
}


void	load_images(t_game *game) 
{
	game->img_width = 32;
	game->img_height = 32;
	game->player_img = mlx_xpm_file_to_image(game->mlx, "images/player_cat.xpm", &game->img_width, &game->img_height);
	if (game->player_img == NULL)
		ft_print_errors_map(10, game);
	game->exit_closed_img = mlx_xpm_file_to_image(game->mlx, "images/exit_closed.xpm", &game->img_width, &game->img_height);
	if (game->exit_closed_img == NULL)
		ft_print_errors_map(10, game);
	game->exit_open_img = mlx_xpm_file_to_image(game->mlx, "images/exit_open.xpm", &game->img_width, &game->img_height);
	if (game->exit_open_img == NULL)
		ft_print_errors_map(10, game);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, "images/collectible.xpm", &game->img_width, &game->img_height);
	if (game->collectible_img == NULL)
		ft_print_errors_map(10, game);
	game->grass_img = mlx_xpm_file_to_image(game->mlx, "images/grass.xpm", &game->img_width, &game->img_height);
	if (game->grass_img == NULL)
		ft_print_errors_map(11, game);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &game->img_width, &game->img_height);
	if (game->wall_img == NULL)
		ft_print_errors_map(11, game);
}
