#include "so_long.h"

/* check the shape of map to be rectangular
   return 1 if yes, return 0 if no */
int	check_shape(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_width)
			return (0);
		i++;
	}
	return (1);
}

/* chech if the map is surrounded by walls
   return 1 if yes, return 0 if no */
int	check_wall(t_game *game)
{
	int	i;

	// check rows
	i = 0;
	while (i < game->map_width)
	{
		if ((game->map[0][i] != '1') || (game->map[game->map_height - 1][i] != '1'))
			return (0);
		i++;
	}
	// check cols
	i = 0;
	while (i < game->map_height)
	{
		if ((game->map[i][0] != '1') || (game->map[i][game->map_width - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

/* check if the map fits all the requirements of 1P, 1E, >0 C
   return 1 if yes, return 0 if no */
int	check_item(t_game *game)
{
	int	i = 0;
	int	j;
	int	exit_count = 0;
	int	player_count = 0;
	int	collectible_count = 0;

	game->collectibles = 0; // initialize at start
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'E') exit_count++;
			else if (game->map[i][j] == 'P') player_count++;
			else if (game->map[i][j] == 'C')
			{
				collectible_count++;
				game->collectibles++;
			}
			else if (game->map[i][j] != '0' && game->map[i][j] != '1') return (0);
			j++;
		}
		i++;
	}
	return (exit_count == 1 && player_count == 1 && collectible_count > 0);
}

/* find player's position */
void	player_pos(t_game *game, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = 0;
	*player_x = -1;
	*player_y = -1;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				*player_x = i;
				*player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

/* create a copy of map to store the flood filled areas & initialize with 0 */
int	**duplicate_map(t_game *game)
{
	int	**temp_map;
	int	i;
	int	j;

	i = 0;
	temp_map = malloc(game->map_height * sizeof(int *));
	if (!temp_map)
		return (NULL);
	while (i < game->map_height)
	{
		temp_map[i] = malloc(game->map_width * sizeof(int));
		if (!temp_map[i])
		{
			while (i >= 0)
				free(temp_map[i--]);
			free(temp_map);
			return (NULL);
		}
		j = 0;
		while (j < game->map_width)
			temp_map[i][j++] = 0;
		i++;
	}
	return (temp_map);
}

/* free the temp map */
void	free_tempmap(int **temp_map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(temp_map[i]);
		i++;
	}
	free(temp_map);
}

/* flood fill function */
void	flood_fill(t_game *game, int **temp_map, int x, int y)
{
	// check the boundaries and if the cell is a wall or already visited
	if (x < 0 || y < 0 || x >= game->map_height || y >= game->map_width || 
		game->map[x][y] == '1' || temp_map[x][y] == 1)
		return ;
	// mark the cell as visited
	temp_map[x][y] = 1;
	// recursively visit neighbouring cells: down, up, right, left
	flood_fill(game, temp_map, x + 1, y);
	flood_fill(game, temp_map, x - 1, y);
	flood_fill(game, temp_map, x, y + 1);
	flood_fill(game, temp_map, x, y - 1);
}

/* check accessibility of exit & collectibles after calling flood fill */
int	check_accessibility(t_game *game, int **temp_map)
{
	int	i;
	int	j;

	i = 0;
	// loop through the map
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			// check if the current cell is E or C, and if they are filled
			if ((game->map[i][j] == 'E' || game->map[i][j] == 'C') && temp_map[i][j] == 0)
				return (0); // E and C is not filled, thus not accessible
			j++;
		}
		i++;
	}
	return (1);
}

/* validate if the map fits all requirements */
int	validate_map(t_game *game)
{
	int	**temp_map;
	int	player_x;
	int	player_y;
	int	result;	

	// check map shape, wall, required items	
	if (check_shape(game) == 0 || check_wall(game) == 0 || check_item(game) == 0)
		return (0);
	// duplicate map for flood fill
	temp_map = duplicate_map(game);
	if (!temp_map)
		return (0);
	// find player position
	player_pos(game, &player_x, &player_y);
	if (player_x == -1 || player_y == -1)
	{
		free_tempmap(temp_map, game->map_height);
		return (0);
	}	
	// call flood fill from the player position
	flood_fill(game, temp_map, player_x, player_y);
	// call check_accessibility 
	result = check_accessibility(game, temp_map);
	// free the temp map
	free_tempmap(temp_map, game->map_height);
	return (result);
}
