#include "fdf.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf("the keyboard key { %d }!\n", keycode);
    if (keycode == 99)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}
int	mouse_hook(int keycode, t_vars *vars)
{
	printf("the mouse key { %d }!\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");

	mlx_loop(vars.mlx);
}