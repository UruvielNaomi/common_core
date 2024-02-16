/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:42:39 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/16 13:38:25 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_first_last_column(t_game *game)
{
	int	i;
	int	last_col;

	i = 0;
	last_col = game->map_width - 1;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || (game->map[i][last_col] != '1' && game->map[i][last_col] != '\n'))
		{
			printf("Error\nFirst and last column aren't walls\n");
			close_window(game);
		}
		i++;
	}
}

void	ft_check_first_last_row(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i][j] && game->map[i][j] != '\n')
	{
		if (game->map[i][j] != '1')
		{
			printf("Error\nTop row isn't a wall\n");
			close_window(game);
		}
		j++;
	}
	i = game->rows - 1;
	j = 0;
	while (game->map[i][j] && game->map[i][j] != '\n')
	{
		if (game->map[i][j] != '1')
		{
			printf("Error\nBottom row isn't a wall\n");
			close_window(game);
		}
		j++;
	}
}

void	ft_check_column_lengths(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[0][j] && game->map[0][j] != '\n')
		j++;
	game->map_width = j;
	while (i < game->rows)
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
			j++;
		if (j != game->map_width)
		{
			printf("Error\nMap not rectangluar\n");
			close_window(game);
		}
		i++;
	}
}


void	ft_check_map(t_game *game)
{
	if (game->map[0] == NULL) 
	{
		printf("Error\nMap is empty\n");
		close_window(game);
	}
	ft_check_column_lengths(game);
	ft_check_first_last_row(game);
	ft_check_first_last_column(game);
}

/*

flood_fill(area, size, begin)
area = map
size = x & y (how many rows and colums)
begin = 

If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way, and return "Error\n" followed by an explicit error message of
your choice.
*/