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

#ifndef TEST_H
# define TEST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "../minilibx/mlx.h"

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

	int		fd;
	int		rows;

	char	*addr;
	char	**map;

	t_point	player_pos;
}	t_game;

int		key_press(int keycode, t_game *game);
void	close_window(t_game *game);


#endif
