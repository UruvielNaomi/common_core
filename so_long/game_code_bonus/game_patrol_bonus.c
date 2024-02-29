/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_patrol_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:48:56 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/29 20:15:22 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_patrol_location(t_game *game, int direction)
{
	int	x;
	int y;
	int	prev_x;
	int	prev_y;

	x = game->patrol_pos.x;
	y = game->patrol_pos.y;
	prev_x = game->pat_prev_pos.x;
	prev_y = game->pat_prev_pos.y;

	draw_image(game, game->grass_img, prev_x, prev_y);
	draw_image(game, game->grass_img, x, y);
	
	if (direction == 0 || direction == 1)
		patrol_left_right(game, direction, x, y);
	if (direction == 2 || direction == 3)
		patrol_up_down(game, direction, x, y);
}

int	is_valid_path_patrol(t_game *game, int x, int y)
{
	if (game->map[x][y] == '0')
		return (1);
	else
		return (0);
}

t_point	calculate_direction_patrol(t_game *game, int direction)
{
	t_point	new_pos;

	new_pos.x = game->patrol_pos.x;
	new_pos.y = game->patrol_pos.y;
	if (direction == 0)
		new_pos.y -= 1;
	else if (direction == 1)
		new_pos.y += 1;
	else if (direction == 2)
		new_pos.x -= 1;
	else if (direction == 3)
		new_pos.x += 1;
	return (new_pos);
}

int	move_patrol(t_game *game)
{
	static time_t	last_time;
	time_t			current_time;
	int				direction;
	t_point			new_pos;

	current_time = time(NULL);
	if (current_time - last_time < 1)
		return (0);
	last_time = current_time;
	direction = rand() % 4;
	new_pos = calculate_direction_patrol(game, direction);
	if (is_valid_path_patrol(game, new_pos.x, new_pos.y) == 1)
	{
		game->pat_prev_pos.x = game->patrol_pos.x;
		game->pat_prev_pos.y = game->patrol_pos.y;
		game->map[game->pat_prev_pos.x][game->pat_prev_pos.y] = '0';
		game->patrol_pos.x = new_pos.x;
		game->patrol_pos.y = new_pos.y;
		game->map[new_pos.x][new_pos.y] = 'G';
		update_patrol_location(game, direction);
	}
	return (0);
}
