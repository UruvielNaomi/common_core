/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:41:19 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/15 16:33:20 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *memory_block, int value, size_t num_bytes)
{
	unsigned char	*byte_pointer;

	byte_pointer = (unsigned char *)memory_block;
	while (num_bytes--)
		*byte_pointer++ = (unsigned char)value;
	return (memory_block);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_memset(&game, 0, sizeof(t_game));
		ft_get_map(&game, argv[1]);
		ft_check_map(&game);
		ft_check_map_content(&game);
		ft_find_valid_path(&game);
		// Display the Map
		game.mlx = mlx_init();
		if (game.mlx == NULL)
			return (1);
		game.win = mlx_new_window(game.mlx, 1920, 1080, "So long!");
		if (game.win == NULL)
		{
			close_window(&game);
			free(game.mlx);
			return (1);
		}
		// Implement Player Movement
		mlx_key_hook(game.win, key_press, &game);
		mlx_loop(game.mlx);
	}	
	return (0);
}
