/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:39:19 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/13 11:43:32 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_rows(t_game *game)
{
	int		count;
	char	ch;
	char	prev_ch;
	int		has_chars;

	count = 0;
	has_chars = 0;
	while (read(game->fd, &ch, 1) == 1)
	{
		if (ch != '\n' && ch != '\r' && ch != ' ')
			has_chars = 1;
		if (ch == '\n')
		{
			if (has_chars)
				count++;
			has_chars = 0;
		}
		prev_ch = ch;
	}
	if (prev_ch != '\n' && has_chars)
		count++;
	game->map_height = count;
	game->tile_size = 32;
	return (count);
}

int	ft_get_map(t_game *game, char *str)
{
	int	i;

	i = 0;
	game->fd = open(str, O_RDONLY);
	if (game->fd < 0)
	{
		close (game->fd);
		ft_print_errors_map(11, game);
	}
	game->rows = ft_count_rows(game);
	if (game->rows == 0)
	{
		close (game->fd);
		ft_print_errors_map(11, game);
	}
	close(game->fd);
	game->fd = open(str, O_RDONLY);
	if (game->fd < 0)
		return (0);
	game->map = malloc(sizeof(char *) * game->rows);
	while (i < game->rows)
		game->map[i++] = get_next_line(game->fd);
	close (game->fd);
	return (1);
}

/* 
if (ch != '\n' && ch != '\r' && ch != ' ')
	check if line contains space/carriage return/newline char
*/