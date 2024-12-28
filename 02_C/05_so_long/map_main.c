#include "so_long.h"
#include <stdio.h>

void	free_map(t_game *game)
{
	int	i;

	if (game->map != NULL)
	{
		i = 0;
		while (i < game->map_height)
		{
			if (game->map[i] != NULL)
				free(game->map[i]); // free memory for each row
			i++;
		}
		free(game->map); // free memory for the array of row ptrs
		game->map = NULL;
	}	
}

int	main(int ac, char **av)
{
	int	height;
	t_game game;
    int player_x;
    int player_y;
    int **temp_map;
    int i, j;

	if (ac != 2)
    {
        perror("Error\nNeed a map input\n");
        return (1);
    }

	if (!parse_map(&game, av[1]))
	{
		perror("Error\nFail to open the map\n");
		free_map(&game);
		return (1);
	}

	// test count_map_height function
	height = count_map_height(av[1]);
	printf("map height: %d\n", height);

	// test parse_map function
	printf("map dimension: %d x %d\n", game.map_width, game.map_height);

    // test check_shape & check_wall & check_item
    printf("validation of map shape: %d\n", check_shape(&game));
    printf("validation of map wall: %d\n", check_wall(&game));
    printf("validation of map items: %d\n", check_item(&game));

    // test validate_map function
    printf("final map validation: %d\n", validate_map(&game));

    // test player_pos function
    player_pos(&game, &player_x, &player_y);
    if (player_x == -1 || player_y == -1)
        printf("Player not found!\n");
    else
        printf("Player is at (%d, %d)\n", player_x, player_y);

    // test duplicate_map and free_tempmap function
    temp_map = duplicate_map(&game);
    if (!temp_map)
        perror("Error: failed to duplicate map\n");
    printf("temp map: \n");
    i = 0;
    while (i < game.map_height)
    {
        j = 0;
        while (j < game.map_width)
        {
            printf("%d ", temp_map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    
    // test flood_fill
    flood_fill(&game, temp_map, player_x, player_y);
    printf("temp map after flood fill: \n");
    i = 0;
    while (i < game.map_height)
    {
        j = 0;
        while (j < game.map_width)
        {
            printf("%d ", temp_map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    // test check_accessibility
    if (check_accessibility(&game, temp_map) == 1)
        printf("all items are reachable\n");
    else
        perror("Error\nsome items are not reachable\n");
    
    free_tempmap(temp_map, game.map_height);
    free_map(&game);
    return (0);
}
