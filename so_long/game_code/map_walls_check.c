/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:42:39 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/15 16:13:16 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_first_last_column(t_game *game)
{
	int	i;
	int	j;
	int	last_col;

	i = 0;
	j = 0;
	while (game->map[0][j])
		j++;
	last_col = j - 1;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][last_col] != '1')
		{
			printf("Error\nMap not surrounded by walls\n");
			close_window(game);
			return ;
		}
		i++;
	}
}

void	ft_check_first_last_row(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1')
			{
				printf("Error\nMap not surrounded by walls\n");
				close_window(game);
				return ;
			}
			j++;
		}
		if (i != 0 && i != game->rows - 1)
			break ;
		i = game->rows - 1;
	}
}

void	ft_check_column_lengths(t_game *game)
{
	int	i;
	int	j;
	int	num_col;

	i = 0;
	j = 0;
	while (game->map[0][j])
		j++;
	num_col = j;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j != num_col)
		{
			printf("Error\nMap not rectangluar\n");
			close_window(game);
			return ;
		}
		i++;
	}
}

void	ft_check_map(t_game *game)
{
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