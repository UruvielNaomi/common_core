/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.h										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: Naomi <Naomi@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/09 19:33:50 by Naomi			 #+#	#+#			 */
/*   Updated: 2024/02/14 16:39:52 by Naomi			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "../minilibx/mlx.h"
# include "get_next_line.h"

typedef struct  s_point
{
	int		   x;
	int		   y;
}			   t_point;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*exit;

	int		fd;
	int		rows;
	int		collectables;
	int		exit_nr;

	char	*addr;
	char	**map;

	t_point	player_pos;
}	t_game;


int		ft_count_rows(t_game *game);
int		ft_get_map(t_game *game, char *str);
int		key_press(int keycode, t_game *game);

void	ft_check_chars(t_game *game);
void	ft_check_column_lengths(t_game *game);
void	ft_check_first_last_column(t_game *game);
void	ft_check_first_last_row(t_game *game);
void	ft_check_map(t_game *game);
void	ft_check_map_content(t_game *game);
void	ft_count_players(t_game *game);
void	ft_find_player_position(t_game *game);
void	ft_find_valid_path(t_game *game);
void	ft_image_to_window(t_game game);
void	ft_xpm_to_image(t_game game);
void	close_window(t_game *game);

#endif
