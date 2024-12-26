#include "so_long.h"
#include <stdio.h>

/* cleanup the map */
void	free_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

int main(int argc, char **argv)
{
    t_game  game;

    if (argc != 2)
    {
        printf("Error\n");
        return (1);
    }

    ft_memset(&game, 0, sizeof(t_game));

    // parse the map
    if (!parse_map(&game, argv[1]))
    {
        printf("Error: Fail to parse the map\n");
        free_map(&game);
        return (1);
    }
    // print map details for testing
    printf("map dimension: %d x %d\n", game.map_width, game.map_height);
    
    // run map validation
    if (!validate_map(&game))
    {
        printf("Error: Invalid map\n");
        free_map(&game);
        return (1);
    }

    // print validation results
    printf("validation results");
    printf("# of items: %d\n", game.collectibles);
    printf("Map is valid\n");

    free_map(&game);
    return (0);
}