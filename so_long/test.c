#include "mlx.h"
#include <unistd.h>

typedef struct s_mlx
{
    void *mlx;
    void *win;
}              t_mlx;

void close_window(t_mlx *mlx)
{
    mlx_destroy_window(mlx->mlx, mlx->win);
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

    mlx.mlx = mlx_init();
    if (mlx.mlx == NULL)
        return (1); // initialization failed
    mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello world!");
    mlx_key_hook(mlx.win, key_press, &mlx);
    mlx_loop(mlx.mlx);
    return (0);
}
