/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:39:19 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/14 16:50:15 by Naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void ft_get_map(t_game *game, char **argv)
{
	char *map;
	
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		map = get_next_line(game->fd);
	}
	close (game->fd);
}