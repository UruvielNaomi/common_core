/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:29:04 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/14 15:29:51 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		close_window(game);
		exit(0); // Exit the program after closing the window
	}
	return (0);
}