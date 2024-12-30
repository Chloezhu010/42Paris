#include "so_long.h"

int main(int ac, char **av)
{
    t_game  game;

    if (ac != 2)
    {
        perror("Error\nNeed a map input\n");
        return (1);
    }

    // parse and validate map
    if (!parse_map(&game, av[1]))
	{
		perror("Error\nFail to open the map\n");
		//free_map(&game);
		return (1);
	}

    // check map items and count collectibles
    if (!check_item(&game))
    {
        perror("Error\nInvalid map items\n");
        //free_map(&game);
        return (1);
    }

    // initialize the game
    init_game(&game);

    // update player starting position
    player_pos(&game, &game.player_x, &game.player_y);

    // check # of collectiables
    printf("# of collectibles: %d\n", game.collectibles);

    // listen to the keypress hook
    mlx_key_hook(game.win, keypress, &game);

    // render the loop
    mlx_loop_hook(game.mlx, render_frame, &game);

    // click cross can also close the window
    mlx_hook(game.win, 17, 0, cross_close, &game);

    // keep the win open
    mlx_loop(game.mlx);

    return (0);
}
