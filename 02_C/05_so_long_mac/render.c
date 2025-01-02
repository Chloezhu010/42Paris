/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:49:59 by czhu              #+#    #+#             */
/*   Updated: 2024/12/30 12:08:39 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* draws the map, incl. wall, floor, collectibles, exit */
void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0; // row index
	while (i < game->map_height)
	{
		j = 0; // col index
		while (j < game->map_width)
		{
			// draw the floor first
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j * TILE_SIZE, i * TILE_SIZE);
			// then draw other elements on top
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

/* draw the player at the current player position */
void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_y * TILE_SIZE, game->player_x * TILE_SIZE);
}

/* combine the above function and update the win */
int	render_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	render_player(game);
	return (0);
}
