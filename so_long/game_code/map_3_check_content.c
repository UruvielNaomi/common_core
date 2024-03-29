/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3_check_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:42:39 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/03 18:30:14 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_exit_collect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->collectables = 0;
	while (i < game->rows)
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'C')
				game->collectables++;
			if (game->map[i][j] == 'E')
			{
				game->exit_nr++;
				game->exit_pos.x = i;
				game->exit_pos.y = j;
			}
			j++;
		}
		i++;
	}
	if (game->exit_nr != 1 || game->collectables < 1)
		ft_print_errors_map(7, game);
}

void	ft_find_player_position(t_game *game)
{
	int	i;
	int	j;
	int	player_found;

	i = 0;
	player_found = 0;
	while (game->map[i] && !player_found)
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_pos.x = i;
				game->player_pos.y = j;
				player_found = 1;
				break ;
			}
			j++;
		}
		if (player_found)
			break ;
		i++;
	}
}

void	ft_count_players(t_game *game)
{
	int	i;
	int	j;
	int	players;

	i = 0;
	players = 0;
	while (i < game->rows)
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'P')
				players++;
			j++;
		}
		i++;
	}
	if (players == 0 || players > 1)
		ft_print_errors_map(6, game);
}

void	ft_check_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] != '1' &&
			game->map[i][j] != '0' &&
			game->map[i][j] != 'P' &&
			game->map[i][j] != 'C' &&
			game->map[i][j] != 'E')
				ft_print_errors_map(5, game);
			j++;
		}
		i++;
	}
}

void	ft_check_map_content(t_game *game)
{
	ft_check_chars(game);
	ft_count_players(game);
	ft_find_player_position(game);
	ft_check_exit_collect(game);
}
