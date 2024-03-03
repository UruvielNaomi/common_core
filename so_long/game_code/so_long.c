/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:41:19 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/03 18:56:19 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

int	initialize_map_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	game->win = mlx_new_window(game->mlx, game->map_width * game->tile_size, \
		game->map_height * game->tile_size, "So long!");
	if (game->win == NULL)
		close_window(game);
	load_images(game);
	load_images_bonus(game);
	ft_images_to_window(game);
	ft_images_to_window_bonus(game);
	step_counter_window(game);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, move_patrol, game);
	mlx_loop(game->mlx);
	return (0);
}

void	all_map_checks(t_game *game)
{
	ft_check_map(game);
	ft_check_map_content(game);
	ft_find_valid_path(game);
}

int	main(int argc, char **argv)
{
	t_game			game;

	if (argc == 2)
	{
		check_file(argv[1]);
		ft_memset(&game, 0, sizeof(t_game));
		ft_get_map(&game, argv[1]);
		all_map_checks(&game);
		if (initialize_map_graphics(&game) == 1)
			return (1);
	}
	return (0);
}
