/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2_walls_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:42:39 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/21 16:52:49 by nstacia          ###   ########.fr       */
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
		if (game->map[i][0] != '1' || (game->map[i][last_col] != '1' \
			&& game->map[i][last_col] != '\n'))
			ft_print_errors_map(4, game);
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
			ft_print_errors_map(2, game);
		j++;
	}
	i = game->rows - 1;
	j = 0;
	while (game->map[i][j] && game->map[i][j] != '\n')
	{
		if (game->map[i][j] != '1')
			ft_print_errors_map(3, game);
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
			ft_print_errors_map(1, game);
		i++;
	}
}

void	ft_check_map(t_game *game)
{
	if (game->map[0] == NULL)
	{
		ft_printf("Error\nMap is empty\n");
		close_window(game);
	}
	ft_check_column_lengths(game);
	ft_check_first_last_row(game);
	ft_check_first_last_column(game);
}
