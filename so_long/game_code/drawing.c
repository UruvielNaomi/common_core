#include "so_long.h"

void	ft_xpm_to_image(t_game game)
{
	/*
	int bits_per_pixel;
	int line_length;
	int endian;
	*/
	int x;
	int y;

	game.img = mlx_xpm_file_to_image(game.mlx, "filename", x, y);
	// game.addr = mlx_get_data_addr(game.img, &bits_per_pixel, &line_length, &endian);
}

void	ft_image_to_window(t_game game)
{
	int x;
	int y;

	mlx_put_image_to_window(game.mlx, game.win, game.img, x, y);
}