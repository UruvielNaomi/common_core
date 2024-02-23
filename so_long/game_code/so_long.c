/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:41:19 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/23 15:33:55 by Naomi            ###   ########.fr       */
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
		game.mlx = mlx_init();
		if (game.mlx == NULL)
			return (1);
		game.win = mlx_new_window(game.mlx, 320, 320, "So long!");
		if (game.win == NULL)
			close_window(&game);
		load_images(&game);
		ft_images_to_window(&game);
		mlx_key_hook(game.win, key_press, &game);
		mlx_hook(game.win, 17, 0, close_window, &game);
		mlx_loop(game.mlx);
	}	
	return (0);
}
