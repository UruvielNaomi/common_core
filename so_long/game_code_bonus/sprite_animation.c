/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:14:37 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/29 20:32:38 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	patrol_left_right(t_game *game, int direction, int x, int y)
{
	time_t	now;
	int		frame;

	now = time(NULL);
	frame = (now * 6) % 2;
	if (direction == 0)
	{
		if (frame == 0)
			draw_image(game, game->patrol_img_l, x, y);
		else
			draw_image(game, game->patrol_img_l2, x, y);
	}
	if (direction == 1)
	{
		if (frame == 0)
			draw_image(game, game->patrol_img_r, x, y);
		else
			draw_image(game, game->patrol_img_r2, x, y);
	}
}

void	patrol_up_down(t_game *game, int direction, int x, int y)
{
	if (direction == 2)
		draw_image(game, game->patrol_img_b, x, y);
	if (direction == 3)
		draw_image(game, game->patrol_img_r, x, y);
}
