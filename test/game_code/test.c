#include "test.h"

int main(void)
{
	t_game game;
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1); // initialization failed
	game.win = mlx_new_window(game.mlx, 1920, 1080, "So long!");
	if (game.win == NULL)
	{
		close_window(&game);
		free(game.mlx);
		return (1); // window creation failed.
	}
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}