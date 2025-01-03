#include "minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 500
#define CIRCLE_R 20
#define MOVE_SPEED 10
#define ESC_KEY 53

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		x_pos;
	int		y_pos;
} t_game;

/* draw a circle */
void	draw_circle(t_game *game)
{
	int	x, y;

	for (y = -CIRCLE_R; y <= CIRCLE_R; y++)
	{
		for (x = -CIRCLE_R; x <= CIRCLE_R; x++)
		{
			if (x * x + y * y <= CIRCLE_R * CIRCLE_R)
				mlx_pixel_put(game->mlx, game->win, game->x_pos + x, game->y_pos + y, 0xFF0000);
		}
	}
}

/* clear the screen */
void	clear_screen(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
}

/* handle key presses */
int	keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == 13) // move up
		game->y_pos -= MOVE_SPEED;
	else if (keycode == 1) // move down
		game->y_pos += MOVE_SPEED;
	else if (keycode == 0) // move left
		game->x_pos -= MOVE_SPEED;
	else if (keycode == 2) // move right
		game->x_pos += MOVE_SPEED;
	return (0);
}

/* update and render the circle */
int	render(t_game *game)
{
	clear_screen(game);
	draw_circle(game);
	return (0);
}

int	main()
{
	t_game	game;

	/* initialize the game structure */
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "move circle");
	game.x_pos = WIDTH / 2;
	game.y_pos = HEIGHT / 2;

	/* hook event when pressing keys */
	mlx_key_hook(game.win, keypress, &game); // listen for key presses
	mlx_loop_hook(game.mlx, render, &game); // continously render the circle

	/* start the event lopp */
	mlx_loop(game.mlx);
	return(0);
}