#include "so_long.h"

void close_window(t_mlx *mlx)
{
    mlx_destroy_window(mlx->mlx_connect, mlx->window);
}

int key_press(int keycode, t_mlx *mlx)
{
    if (keycode == 53) // 53 is the keycode for the escape key on a Mac.
    {
        close_window(mlx);
        exit(0); // Exit the program after closing the window
    }
    return (0);
}

int main(void)
{
    t_mlx mlx;

    mlx.mlx_connect = mlx_init();
    if (mlx.mlx_connect == NULL)
        return (1); // initialization failed
    mlx.window = mlx_new_window(mlx.mlx_connect, 1920, 1080, "So_long!");
    mlx_key_hook(mlx.window, key_press, &mlx);
    mlx_loop(mlx.mlx_connect);
    return (0);
}
