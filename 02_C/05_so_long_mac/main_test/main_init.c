#include "so_long.h"

int	main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
    {
        perror("Error\nNeed a map input\n");
        return (1);
    }
    // initialize all ptrs to be NULL
    game.mlx = NULL;
    game.win = NULL;
    game.img_collectible = NULL;
    game.img_exit = NULL;
    game.img_floor = NULL;
    game.img_player = NULL;
    game.img_wall = NULL;

    // parse and validate map
    if (!parse_map(&game, av[1]))
	{
		perror("Error\nFail to open the map\n");
		//free_map(&game);
		return (1);
	}
    printf("map dimension: %d x %d\n", game.map_width, game.map_height);
    // initialize game
    init_game(&game);
    // verify texture loading
    printf("texture player: %p\n", game.img_player);
    printf("texture player: %p\n", game.img_wall);
    printf("texture player: %p\n", game.img_collectible);
    printf("texture player: %p\n", game.img_exit);
    printf("texture player: %p\n", game.img_floor);

    // keep the window open
    mlx_loop(game.mlx);

    // cleanup afterwards
    cleanup_texture(&game);
    mlx_destroy_window(game.mlx, game.win);
    // mlx_destroy_display(game.mlx);
    free(game.mlx);
    free_map(&game);

    return (0);
}
