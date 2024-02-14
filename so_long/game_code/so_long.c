#include "so_long.h"
#include "mlx.h"

static void	*ft_memset(void *memoryBlock, int value, size_t numBytes)
{
	unsigned char	*bytePointer;

	bytePointer = (unsigned char *)memoryBlock;
	while (numBytes--)
		*bytePointer++ = (unsigned char)value;
	return (memoryBlock);
}


int main(void)
{
	t_game game;
	
	ft_memset(&game, 0, sizeof(t_game));
	//maps
	//errors
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1); // initialization failed
	game.win = mlx_new_window(game.mlx, 1920, 1080, "So long!");
	if (game.win == NULL)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (1); // window creation failed.
	}
	
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
