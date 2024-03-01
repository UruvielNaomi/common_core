/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_4_bucket_fill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:33:59 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/01 13:57:28 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_copy(char **map_copy, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

char	**copy_map(char **map, t_point size)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * size.y);
	if (!copy)
		return (NULL);
	while (i < size.y)
	{
		copy[i] = (char *)malloc(sizeof(char) * size.x);
		ft_memcpy(copy[i], map[i], size.x);
		i++;
	}
	return (copy);
}

void	reach_collectibles(char **map, t_point size, t_point cur, int *coll)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == 'V')
		return ;
	if (map[cur.y][cur.x] == 'C' )
	{
		(*coll) -= 1;
		map[cur.y][cur.x] = 'V';
		if (*coll == 0)
			return ;
	}
	else
		map[cur.y][cur.x] = 'V';
	reach_collectibles(map, size, (t_point){cur.x - 1, cur.y}, coll);
	reach_collectibles(map, size, (t_point){cur.x + 1, cur.y}, coll);
	reach_collectibles(map, size, (t_point){cur.x, cur.y - 1}, coll);
	reach_collectibles(map, size, (t_point){cur.x, cur.y + 1}, coll);
}

void	reach_exit(char **map, t_point size, t_point cur, int *found_exit)
{
	if (*found_exit || cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || map[cur.y][cur.x] == '1'
		|| map[cur.y][cur.x] == 'V')
		return ;
	if (map[cur.y][cur.x] == 'E' )
	{
		*found_exit = 1;
		return ;
	}
	else
		map[cur.y][cur.x] = 'V';
	reach_exit(map, size, (t_point){cur.x - 1, cur.y}, found_exit);
	reach_exit(map, size, (t_point){cur.x + 1, cur.y}, found_exit);
	reach_exit(map, size, (t_point){cur.x, cur.y - 1}, found_exit);
	reach_exit(map, size, (t_point){cur.x, cur.y + 1}, found_exit);
}

void	ft_find_valid_path(t_game *game)
{
	t_point	size;
	char	**map_copy;
	int		coll;
	int		ex;

	size.x = game->map_width;
	size.y = game->map_height;
	map_copy = copy_map(game->map, size);
	coll = game->collectables;
	reach_collectibles(map_copy, size, game->player_pos, &coll);
	free_map_copy(map_copy, game->rows);
	if (coll != 0)
		ft_print_errors_map(8, game);
	map_copy = copy_map(game->map, size);
	ex = 0;
	reach_exit(map_copy, size, game->player_pos, &ex);
	free_map_copy(map_copy, game->rows);
	if (!ex)
		ft_print_errors_map(9, game);
}
