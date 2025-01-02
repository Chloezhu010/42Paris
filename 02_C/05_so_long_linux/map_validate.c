/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:49:45 by czhu              #+#    #+#             */
/*   Updated: 2025/01/02 14:21:32 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	i = 0;
	while (i < game->map_width)
	{
		if ((game->map[0][i] != '1')
			|| (game->map[game->map_height - 1][i] != '1'))
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if ((game->map[i][0] != '1')
			|| (game->map[i][game->map_width - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

/* helper function for check_item */
int	item_helper(t_game *game, int *exit_count,
		int *player_count, int *collectible_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'E')
				(*exit_count)++;
			else if (game->map[i][j] == 'P')
				(*player_count)++;
			else if (game->map[i][j] == 'C')
			{
				(*collectible_count)++;
				game->collectibles++;
			}
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* check if the map fits all the requirements of 1P, 1E, >0 C
   return 1 if yes, return 0 if no */
int	check_item(t_game *game)
{
	int	exit_count;
	int	player_count;
	int	collectible_count;

	exit_count = 0;
	player_count = 0;
	collectible_count = 0;
	game->collectibles = 0;
	if (item_helper(game, &exit_count, &player_count, &collectible_count) == 0)
		return (0);
	return (exit_count == 1 && player_count == 1 && collectible_count > 0);
}

/* validate if the map fits all requirements */
int	validate_map(t_game *game)
{
	int	**temp_map;
	int	player_x;
	int	player_y;
	int	result;	

	if (!game || !game->map)
		return (0);
	if (check_shape(game) == 0 || check_wall(game) == 0
		|| check_item(game) == 0)
		return (0);
	temp_map = duplicate_map(game);
	if (!temp_map)
		return (0);
	player_pos(game, &player_x, &player_y);
	if (player_x == -1 || player_y == -1)
	{
		free_tempmap(temp_map, game->map_height);
		return (0);
	}	
	flood_fill(game, temp_map, player_x, player_y);
	result = check_accessibility(game, temp_map);
	free_tempmap(temp_map, game->map_height);
	return (result);
}
