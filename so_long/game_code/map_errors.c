#include "so_long.h"

void	ft_find_player_position(t_game *game)
{
	// find begin coordinates for player character.
	// iterate over map: 2 nested loops.
	// outer loop for rows
	// inner loop for columns
	// check for P char
	// store coordinates for P char in t_point player_pos
	// finish search once P is found.
}
void	ft_check_first_last_column(t_game *game)
{

}
void	ft_check_first_last_row(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (j == '1')
				j++;
			else
			{
				printf("Error\n");
				printf("Map not surrounded by walls\n");
				close_window(game);
				return;
			}
		}
		if (i != game->rows - 1)
			i = game->rows - 1;
		else
		break;
	}
}
void	ft_check_column_lengths(t_game *game)
{
	int i;
	int j;
	int num_col;

	i = 0;
	j = 0;
	while(game->map[0][j])
		j++;
	num_col = j;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j != num_col)
		{
			printf("Error\n");
			printf("Map not rectangluar\n");
			close_window(game);
			return;
		}
		i++;
	}
}
void	ft_check_rectangular(t_game *game)
{
	ft_check_column_lengths(game);
	ft_check_first_last_row(game);
	ft_check_first_last_column(game);
	// check if first and last row are nothing but 1s
	// check if every first and last column is a 1
}

void	ft_check_map(t_game *game)
{
	ft_check_rectangular(game);
	ft_find_player_position(game);
	ft_find_valid_path(game);
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