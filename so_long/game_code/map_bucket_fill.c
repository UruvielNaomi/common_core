/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bucket_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:33:59 by nstacia           #+#    #+#             */
/*   Updated: 2024/02/15 19:01:38 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void	*dest, void const *src, size_t len)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	dest_ptr = dest;
	src_ptr = src;
	if (!dest && !src)
		return (dest);
	while (len > 0)
	{
		*dest_ptr++ = *src_ptr++;
		len--;
	}
	return (dest);
}

char	**copy_map(char **map, t_point size)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * size.y);
	while (i < size.y)
	{
		copy[i] = (char *)malloc(sizeof(char) * size.x);
		ft_memcpy(copy[i], map[i], size.x);
		i++;
	}
	return (copy);
}


void	flood_fill(char **map, t_point size, t_point current, int steps)
{
	if (current.y < 0 || current.y >= size.y || current.x < 0 || current.x >= size.x
		|| map[current.y][current.x] == '1' || map[current.y][current.x] == 'V')
		return;

	// Mark the current point as visited
	map[current.y][current.x] = 'V';

	// Check if the current point is a collectible or an exit
	if (map[current.y][current.x] == 'C' || map[current.y][current.x] == 'E')
	{
		// Found a collectible or an exit
		printf("Found a %c at %d steps\n", map[current.y][current.x], steps);
	}

	// Recursively call fill on the neighboring points
	flood_fill(map, size, (t_point){current.x - 1, current.y}, steps + 1);
	flood_fill(map, size, (t_point){current.x + 1, current.y}, steps + 1);
	flood_fill(map, size, (t_point){current.x, current.y - 1}, steps + 1);
	flood_fill(map, size, (t_point){current.x, current.y + 1}, steps + 1);
}

void	ft_find_valid_path(t_game *game)
{
	t_point	size;
	char	**map_copy;
	
	size.x = game->map_width;
	size.y = game->map_height;
	map_copy = copy_map(game->map, size);
	flood_fill(map_copy, size, game->player_pos, 0);
	free(map_copy);
}
