/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:40:47 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/28 11:56:01 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_patrol(t_game *game)
{
	draw_image(game, game->patrol_img_l, game->patrol_pos.x, game->patrol_pos.y);
}

void	find_starting_position_patrol(t_game *game)
{
	int	i;
	int	j;

	i = game->map_height - 1;
	j = game->map_width - 1;
	while (i >= 0)
	{
		while (j >= 0)
		{
			if (game->map[i][j] == '0')
			{
				game->patrol_pos.x = i;
				game->patrol_pos.y = j;
				draw_patrol(game);
				return ;
			}
			j--;
		}
		i--;
	}
}
