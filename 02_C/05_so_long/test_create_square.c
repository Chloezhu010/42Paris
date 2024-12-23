#include "minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 500

/* test to initialize the connection, win, and create a square with random color */
int	main()
{
	void	*mlx;
    void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "hello world!");

	for (int i = HEIGHT * 0.1; i < HEIGHT * 0.9; i++)
	{
		for (int j = WIDTH * 0.1; j < WIDTH * 0.9; j++)
		{
			mlx_pixel_put(mlx, mlx_win, j, i, rand() % 0x1000000);
		}
	}
	mlx_string_put(mlx, mlx_win, WIDTH * 0.75, HEIGHT * 0.95, 0xffffff, "czhu random gen");
	mlx_loop(mlx);
}