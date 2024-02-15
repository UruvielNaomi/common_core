/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:29:04 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/15 11:21:58 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_game *game)
{
    int i;

    for (i = 0; i < game->rows; i++)
    {
        free(game->map[i]);  // Free each row
    }
    free(game->map);  // Free the array of pointers
}

void close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0); // program succesfully exited
}

int key_press(int keycode, t_game *game)
{
	if (keycode == 53) // 53 is the keycode for the escape key on a Mac. It might be different on your system.
	{
		free_map(game);
		close_window(game);
		exit(0); // Exit the program after closing the window
	}
	return (0);
}