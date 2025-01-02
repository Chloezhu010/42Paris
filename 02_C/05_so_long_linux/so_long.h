/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:27:37 by czhu              #+#    #+#             */
/*   Updated: 2025/01/02 15:28:56 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

# define TILE_SIZE 64

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
	void	*img_exit_open;
	void	*img_floor;
	int		dx;
	int		dy;
}	t_game;

/* init.c */
void	init_game(t_game *game);
void	load_texture(t_game *game);
void	cleanup_texture(t_game *game);

/* map.c */
int		count_map_height(char *map_path);
int		parse_map(t_game *game, char *map_path);

/* map_validate.c*/
int		check_shape(t_game *game);
int		check_wall(t_game *game);
int		check_item(t_game *game);
int		validate_map(t_game *game);

/* map_floodfill.c*/
void	player_pos(t_game *game, int *player_x, int *player_y);
int		**duplicate_map(t_game *game);
void	free_tempmap(int **temp_map, int height);
void	flood_fill(t_game *game, int **temp_map, int x, int y);
int		check_accessibility(t_game *game, int **temp_map);

/* render.c */
void	render_map(t_game *game);
void	render_player(t_game *game);
int		render_frame(t_game *game);

/* movement.c */
void	move_player(t_game *game, int dx, int dy);

/* movement_key.c */
int		keypress(int keycode, t_game *game);
int		cross_close(t_game *game);

/* cleanup.c */
void	free_map(t_game *game);
void	cleanup(t_game *game);

#endif
