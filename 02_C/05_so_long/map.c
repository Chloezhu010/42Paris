/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:43:34 by czhu              #+#    #+#             */
/*   Updated: 2024/12/26 13:22:58 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* calculate map height */
int	count_map_line(char *map_path)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		height++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (height);
}

/* read and parse the map */
int	parse_map(t_game *game, char *map_path)
{
	int		fd;
	int		i;
	char	*line;

	game->map_height = count_map_line(map_path);
	if (game->map_height == 0)
		return (0);
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	fd = open(map_path, O_RDONLY);
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
	//return (validate_map(game));
	return (1);
}