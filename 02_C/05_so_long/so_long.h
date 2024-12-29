/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:27:37 by czhu              #+#    #+#             */
/*   Updated: 2024/12/25 14:58:39 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

# define TILE_SIZE 32

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	void	*img_player;
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit;
	void	*img_floor;
}	t_game;

/* init.c */
void	init_game(t_game *game);
void	*load_single_texture(void *mlx, char *path, int *width, int *height);
void	load_texture(t_game *game);

/* map.c */
int		count_map_height(char *map_path);
int		parse_map(t_game *game, char *map_path);

/* map_utils.c*/
int		check_shape(t_game *game);
int		check_wall(t_game *game);
int		check_item(t_game *game);
void	player_pos(t_game *game, int *player_x, int *player_y);
int		**duplicate_map(t_game *game);
void	free_tempmap(int **temp_map, int height);
void	flood_fill(t_game *game, int **temp_map, int x, int y);
int		check_accessibility(t_game *game, int **temp_map);
int		validate_map(t_game *game);

/* movement.c */

/* render.c */

/* utils.c */

#endif
