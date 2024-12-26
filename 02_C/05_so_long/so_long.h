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
# include "libft/libft.h"

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
	void	*img_item;
	void	*img_exit;
	void	*img_floor;
}	t_game;

/* init.c */

/* map.c */
int		count_map_line(char *map_path);
int		parse_map(t_game *game, char *map_path);

/* check_map.c*/
int		check_rectangular(t_game *game);
int		check_wall(t_game *game);
int		validate_map(t_game *game);

/* movement.c */

/* render.c */

/* utils.c */

#endif
