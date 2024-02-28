/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:40:47 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/28 13:25:47 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_starting_position_patrol(t_game *game)
{
	int	i;
	int	j;
	int	found;

	i = game->map_height - 1;
	found = 0;
	while (i >= 0 && !found)
	{
		j = game->map_width - 1;
		while (j >= 0 && !found)
		{
			if (game->map[i][j] == '0')
			{
				game->patrol_pos.y = j;
				game->patrol_pos.x = i;
				game->map[i][j] = 'G';
				found = 1;
			}
			j--;
		}
		i--;
	}
}

