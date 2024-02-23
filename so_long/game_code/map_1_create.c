/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:39:19 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/23 16:34:24 by Naomi            ###   ########.fr       */
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
	return (count);
}

int	ft_get_map(t_game *game, char *str)
{
	int	i;

	i = 0;
	game->fd = open(str, O_RDONLY);
	if (game->fd < 0)
		return (0);
	game->rows = ft_count_rows(game);
	if (game->rows == 0)
	{
		ft_printf("Error\nFile is empty\n");
		close (game->fd);
		return (0);
	}
	close(game->fd);
	game->fd = open(str, O_RDONLY);
	if (game->fd < 0)
		return (0);
	game->map = malloc(sizeof(char *) * game->rows);
	while (i < game->rows)
	{
		game->map[i] = get_next_line(game->fd);
		i++;
	}
	close (game->fd);
	return (1);
}
