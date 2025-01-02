/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:49:35 by czhu              #+#    #+#             */
/*   Updated: 2025/01/02 12:54:14 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_height(char *map)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		height ++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (height);
}

int	parse_map(t_game *game, char *map)
{
	int		fd;
	int		i;
	char	*line;

	game->map_height = count_map_height(map);
	if (game->map_height == 0)
		return (free(game->map), game->map = NULL, 0);
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (free(game->map), game->map = NULL, 0);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (free(game->map), game->map = NULL, 0);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < game->map_height)
	{
		game->map[i] = line;
		if (i++ == 0)
			game->map_width = ft_strlen(line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}
