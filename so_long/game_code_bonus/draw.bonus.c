/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:26:27 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/01 10:36:59 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_images_to_window_bonus(t_game *game)
{
	find_starting_position_patrol(game);
	draw_image(game, game->patrol_img_l, game->patrol_pos.x, \
		game->patrol_pos.y);
}

void	load_images_bonus(t_game *game)
{
	game->img_width = 32;
	game->img_height = 32;
	load_image(game, &game->patrol_img_r, "images/ghost_r.xpm");
	load_image(game, &game->patrol_img_r2, "images/ghost_r2.xpm");
	load_image(game, &game->patrol_img_l, "images/ghost_l.xpm");
	load_image(game, &game->patrol_img_l2, "images/ghost_l2.xpm");
	load_image(game, &game->patrol_img_b, "images/ghost_b.xpm");
}
