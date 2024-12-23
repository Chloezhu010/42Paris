#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 500
#define ESC_KEY 53

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

/* press esc to close the win */
int	esc_close(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

/* click cross to close the win */
int	cross_close(t_vars *vars)
{
	(void)vars;
	exit(0);
}

/* press key and print out keycode */
int key_hook(int keycode, t_vars *vars)
{
    printf("Steps taken: %d\n", keycode);
    return (0);
}

int	main()
{
	t_vars	vars;

	/* initialize the connection & new window */
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, HEIGHT, WIDTH, "hello world");
	/* key hook*/
	mlx_key_hook(vars.win, key_hook, &vars);
	/* 2 methods to close the win*/
	mlx_hook(vars.win, 02, 1L<<0, esc_close, &vars);
	mlx_hook(vars.win, 17, 0, cross_close, NULL);
	/* loop to maintain the connection */
	mlx_loop(vars.mlx);
	return (0);
}
