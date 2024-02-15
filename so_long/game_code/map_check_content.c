/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:42:39 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/15 15:55:56 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_valid_path(t_game *game)
{
	
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
		while (game->map[i][j])
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
		i++;
	}
	if (!player_found)
		printf("Error\nNo Player Found\n");
}

void	ft_check_map_content(t_game *game)
{
	ft_find_player_position(game);
	ft_find_valid_path(game);	
}