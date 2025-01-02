/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_floodfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:12:56 by czhu              #+#    #+#             */
/*   Updated: 2025/01/02 13:22:38 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			while (i > 0)
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
	if (x < 0 || y < 0 || x >= game->map_height || y >= game->map_width
		|| game->map[x][y] == '1' || temp_map[x][y] == 1)
		return ;
	temp_map[x][y] = 1;
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
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if ((game->map[i][j] == 'E'
				|| game->map[i][j] == 'C') && temp_map[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
