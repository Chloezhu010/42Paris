/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:27:45 by czhu              #+#    #+#             */
/*   Updated: 2024/12/26 17:40:37 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* duplicate the map to use for flood fill*/
char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			return (free(copy), NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

/* flood fill algo*/
void	flood_fill(char **map, int x, int y, int width, int height)
{
}


int	check_rectangular(t_game *game)
{
	int i;
	
	i = 0;
	while (i < game->map_height)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_width)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_game *game)
{
	int	i;

	/* check rows */
	i = 0;
	while (i < game->map_width)
	{
		if ((game->map[0][i] != '1') || (game->map[game->map_height - 1][i] != '1'))
			return (0);
		i++;
	}
	/* check columns */
	i = 0;
	while (i < game->map_height)
	{
		if ((game->map[i][0]) != '1' || (game->map[i][game->map_width - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}	

int	validate_map(t_game *game)
{
	int	i;
	int	j;
	int	exit_count;
	int	player_count;
	int	item_count;

	/* check map shape & wall */
	if (check_rectangular(game) == 0 || check_wall(game) == 0)
		return (0);
	/* initialize the counters*/
	exit_count = 0;
	player_count = 0;
	item_count = 0;
	/* loop & check map content */
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'E')
				exit_count++;
			else if (game->map[i][j] == 'P')
				player_count++;
			else if (game->map[i][j] == 'C')
				item_count++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	/* store collectible count for later use */
	game->collectibles = item_count;
	/* return if exit is 1, player is 1, collectibles more than 0 */
	return (exit_count == 1 && player_count == 1 && item_count > 0);
}
