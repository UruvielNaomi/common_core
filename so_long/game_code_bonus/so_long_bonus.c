/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:40:47 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/29 13:11:42 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line.h"

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

void	step_counter_window(t_game *game)
{
	char	*str1;

	str1 = "Steps: ";
	game->str2 = ft_itoa(game->count_moves);
	game->str3 = ft_strjoin(str1, game->str2);
	mlx_string_put(game->mlx, game->win, game->map_width, \
	game->map_height - (game->map_height / 20), 0xFFFFFF, game->str3);
}

void	update_step_counter_window(t_game *game)
{
	char	*str1;
	int y;

	str1 = "Steps: ";
	y = 0;
	if (game->str2)
		free(game->str2);
	game->str2 = ft_itoa(game->count_moves);
	if (game->str3)
		free(game->str3);
	game->str3 = ft_strjoin(str1, game->str2);
	while (y < game->map_width)
	{
		draw_image(game, game->wall_img, 0, y);
		y++;
	}
	mlx_string_put(game->mlx, game->win, \
		game->map_width, \
		game->map_height, \
		0xFFFFFF, game->str3);
}

void	patrol_encounter(t_game *game)
{
	ft_printf("G A M E   O V E R !");
	close_window(game);
}
