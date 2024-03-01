/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:39:19 by Naomi             #+#    #+#             */
/*   Updated: 2024/03/01 12:11:11 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	ft_count_rows(t_game *game)
{
	int		count;
	char	ch;
	char	prev_ch;

	count = 0;
	while (read(game->fd, &ch, 1) == 1)
	{
		if (ch == '\n')
			count++;
		prev_ch = ch;
	}
	if (prev_ch != '\n')
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
		ft_printf("Error\nEmpty file/non valid path\n");
		exit (1);
	}
	game->rows = ft_count_rows(game);
	if (game->rows == 0)
	{
		close (game->fd);
		ft_printf("Error\nEmpty file/non valid path\n");
		exit (1);
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

/* TRIED TEMPORARY ROW FOR GET NEXT LINE, STILL MEMORY LEAKS. :(
int	ft_get_map(t_game *game, char *str)
{
	int	i;
	char *row;

	i = 0;
	game->fd = open(str, O_RDONLY);
	if (game->fd < 0)
	{
		close (game->fd);
		ft_printf("Error\nEmpty file/non valid path\n");
		exit (1);
	}
	game->rows = ft_count_rows(game);
	if (game->rows == 0)
	{
		close (game->fd);
		ft_printf("Error\nEmpty file/non valid path\n");
		exit (1);
	}
	close(game->fd);
	game->fd = open(str, O_RDONLY);
	if (game->fd < 0)
		return (0);
	game->map = malloc(sizeof(char *) * game->rows);
	while (i < game->rows)
	{
		// game->map[i++] = get_next_line(game->fd);
		row = get_next_line(game->fd);
		game->map[i] = ft_strdup(row);
		free (row);
		i++;
	}
	i = 0;
	close (game->fd);
	return (1);
}
*/
