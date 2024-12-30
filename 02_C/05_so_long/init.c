#include "so_long.h"

void	init_game(t_game *game)
{
	// initialize the connection
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error\nFailed to initialize minilibx\n");
		exit (1);
	}
	// initialize the windown
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		perror("Error\nFailed to create win\n");
		//mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit (1);
	}
	game->moves = 0;
	// load the textures
	load_texture(game);
}

void	*load_single_texture(void *mlx, char *path, int *width, int *height)
{
	// load the texture from the xpm file
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, width, height);
	if (!img)
	{
		perror("Error\nFailed to load texture\n");
		exit(1);
	}
	return (img);
}

void	cleanup_texture(t_game *game)
{
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
}

void	load_texture(t_game *game)
{
	int	width = TILE_SIZE;
	int	height = TILE_SIZE;

	game->img_player = load_single_texture(game->mlx, "./textures/player.xpm", &width, &height);
	game->img_wall = load_single_texture(game->mlx, "./textures/wall.xpm", &width, &height);
	game->img_collectible = load_single_texture(game->mlx, "./textures/collectible.xpm", &width, &height);
	game->img_exit = load_single_texture(game->mlx, "./textures/exit.xpm", &width, &height);
	game->img_floor = load_single_texture(game->mlx, "./textures/floor.xpm", &width, &height);
	if (!game->img_player || !game->img_wall || !game->img_collectible || !game->img_exit || !game->img_floor)
	{
		cleanup_texture(game);
		mlx_destroy_window(game->mlx, game->win);
		//mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
}
