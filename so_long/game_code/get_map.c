/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:39:19 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/15 12:14:43 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_rows(t_game *game, char **argv)
{
	int	count;
	char ch;

	count = 0;
	while (read(game->fd, &ch, 1) == 1)
	{
		if (ch == '\n')
			count++;
	}
	if (ch != '\n')
		count++;
	return (count);
}

void 	ft_get_map(t_game *game, char **argv)
{
	int i = 0;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	game->rows = ft_count_rows(game, argv[1]);
	close(game->fd);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	game->map = malloc(sizeof(char *) * game->rows);
	while (i < game->rows)
	{
		game->map[i] = get_next_line(game->fd);
		i++;
	}
	close (game->fd);
}

void	ft_check_map(t_game *game)
{
	
}

/*

flood_fill(area, size, begin)
area = map
size = x & y (how many rows and colums)
begin = 

/* 
If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way, and return "Error\n" followed by an explicit error message of
your choice.
*/