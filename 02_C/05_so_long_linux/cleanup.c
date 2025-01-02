/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:37:12 by czhu              #+#    #+#             */
/*   Updated: 2025/01/02 12:57:03 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* free the map when error or at the end */
void	free_map(t_game *game)
{
	int	i;

	if (game->map != NULL)
	{
		i = 0;
		while (i < game->map_height)
		{
			if (game->map[i] != NULL)
				free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}	
}

/* cleanup in the end */
void	cleanup(t_game *game)
{
	if (!game)
		return ;
	free_map(game);
	if (game->mlx)
	{
		cleanup_texture(game);
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}
