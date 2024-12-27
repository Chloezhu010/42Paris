#include "so_long.h"

int	count_map_height(char *map)
{
	int	fd;
	int	height;
	char	*line;

	// initialization
	height = 0;
	fd = open(map, O_RDONLY);
	// input validation
	if (fd < 0)
		return (-1);
	// loop through fd to cal. height
	while ((line = get_next_line(fd)) != NULL)
	{
		height ++;
		free(line);
		line = NULL;
	}
	close (fd);
	return (height);	
}

int	parse_map(t_game *game, char *map)
{
	int	fd;
	int	i;
	char	*line;

	game->map_height = count_map_height(map);
	// input validation
	if (game->map_height == 0)
		return (0);
	// malloc for the map
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	// parse the map line by line
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (free(game->map), game->map = NULL, 0);
	i = 0;
	while ((line = get_next_line(fd)) != NULL && i < game->map_height)
	{
		game->map[i] = line;
		if (i == 0)
			game->map_width = ft_strlen(line);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	// return value
	return (1);
}

#include <stdio.h>

//void	free_map(t_game *game)

int	main(int ac, char **av)
{
	int	height;
	t_game game;

	if (ac != 2)
    {
        printf("Error\nNeed a map input\n");
        return (1);
    }

	if (!parse_map(&game, av[1]))
	{
		printf("Error\nFail to open the map\n");
		//free_map(&game);
		return (1);
	}

	// test count_map_height function
	height = count_map_height(av[1]);
	printf("map height: %d\n", height);

	// test parse_map function
	printf("map dimension: %d x %d\n", game.map_width, game.map_height);
}