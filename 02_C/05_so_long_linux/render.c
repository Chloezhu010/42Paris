/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:49:59 by czhu              #+#    #+#             */
/*   Updated: 2025/01/02 13:46:18 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* helpder function for render_map */
void	render_texture(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_floor, j * TILE_SIZE, i * TILE_SIZE);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == 'E')
	{
		if (game->collectibles == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_exit_open, j * TILE_SIZE, i * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_exit, j * TILE_SIZE, i * TILE_SIZE);
	}
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collectible, j * TILE_SIZE, i * TILE_SIZE);
}

/* draws the map, incl. wall, floor, collectibles, exit */
void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			render_texture(game, i, j);
			j++;
		}
		i++;
	}
}

/* draw the player at the current player position */
void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		game->player_y * TILE_SIZE, game->player_x * TILE_SIZE);
}

/* combine the above function and update the win */
int	render_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	render_player(game);
	return (0);
}
