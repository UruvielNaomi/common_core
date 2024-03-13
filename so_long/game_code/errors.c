/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:45:02 by nstacia           #+#    #+#             */
/*   Updated: 2024/03/13 11:28:25 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	ft_print_errors_map(int error_number, t_game *game)
{
	if (error_number == 1)
		ft_printf("Error\nMap not rectangluar\n");
	else if (error_number == 2)
		ft_printf("Error\nTop row isn't a wall\n");
	else if (error_number == 3)
		ft_printf("Error\nBottom row isn't a wall\n");
	else if (error_number == 4)
		ft_printf("Error\nFirst and last column aren't walls\n");
	else if (error_number == 5)
		ft_printf("Error\nInvalid Map\n");
	else if (error_number == 6)
		ft_printf("Error\nIncorrect number of Players\n");
	else if (error_number == 7)
		ft_printf("Error\nExit or Collectable Amount Error\n");
	else if (error_number == 8)
		ft_printf("Error\nNot all Collectibles found\n");
	else if (error_number == 9)
		ft_printf("Error\nExit has not been found\n");
	else if (error_number == 10)
		ft_printf("Error\nFailed to load an image\n");
	else if (error_number == 11)
		ft_printf("Error\nFile error\n");
	if (game->map != NULL)
		free_map(game);
	exit (1);
}

void	check_file(char *str)
{
	int	file;

	file = open(str, O_RDONLY);
	if (file < 0)
	{
		ft_printf("Error\nEmpty file/non valid path\n");
		exit(1);
	}
	close(file);
}
