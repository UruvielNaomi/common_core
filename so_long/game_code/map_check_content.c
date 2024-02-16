/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:42:39 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/16 15:02:14 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_exit_collect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'C')
				game->collectables++;
			if (game->map[i][j] == 'E')
				game->exit_nr++;		
			j++;
		}
		i++;
	}
	if (game->exit_nr != 1 && game->collectables < 1)
	{
		printf("Error\nExit or Collectable Error");
		close_window(game);
	}
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
	{
		printf("Error\nIncorrect number of Players\n");
		close_window(game);
	}
	printf("You have %d players\n", players);
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
			{
				printf("Error\nInvalid Map\n");
				close_window(game);
			}
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
