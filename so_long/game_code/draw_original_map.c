/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_original_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:35:25 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/29 19:48:19 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

void	draw_image(t_game *game, void *img, int x, int y)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = y * game->img_width;
	pixel_y = x * game->img_height;
	mlx_put_image_to_window(game->mlx, game->win, img, pixel_x, pixel_y);
}

void	ft_images_to_window(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->rows)
	{
		y = 0;
		while (game->map[x][y] && game->map[x][y] != '\n')
		{
			draw_image(game, game->grass_img, x, y);
			if (game->map[x][y] == '1')
				draw_image(game, game->wall_img, x, y);
			if (game->map[x][y] == 'P')
				draw_image(game, game->player_img_r, x, y);
			if (game->map[x][y] == 'C')
				draw_image(game, game->collectible_img, x, y);
			if (game->map[x][y] == 'E')
				draw_image(game, game->exit_closed_img, x, y);
			y++;
		}
		x++;
	}
	find_starting_position_patrol(game);
	draw_image(game, game->patrol_img_l, game->patrol_pos.x, \
		game->patrol_pos.y);
}

void	load_image(t_game *game, void **img, char *path)
{
	*img = mlx_xpm_file_to_image(game->mlx, path, \
		&game->img_width, &game->img_height);
	if (*img == NULL)
		ft_print_errors_map(10, game);
}

void	load_images(t_game *game)
{
	game->img_width = 32;
	game->img_height = 32;
	load_image(game, &game->player_img_r, "images/player_r.xpm");
	load_image(game, &game->player_img_l, "images/player_l.xpm");
	load_image(game, &game->player_img_b, "images/player_br.xpm");
	load_image(game, &game->exit_closed_img, "images/exit_closed.xpm");
	load_image(game, &game->exit_open_img, "images/exit_open.xpm");
	load_image(game, &game->collectible_img, "images/collectible.xpm");
	load_image(game, &game->grass_img, "images/grass.xpm");
	load_image(game, &game->wall_img, "images/wall.xpm");
	load_image(game, &game->patrol_img_r, "images/ghost_r.xpm");
	load_image(game, &game->patrol_img_r2, "images/ghost_r2.xpm");
	load_image(game, &game->patrol_img_l, "images/ghost_l.xpm");
	load_image(game, &game->patrol_img_l2, "images/ghost_l2.xpm");
	load_image(game, &game->patrol_img_b, "images/ghost_b.xpm");
}
