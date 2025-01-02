/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:19:01 by czhu              #+#    #+#             */
/*   Updated: 2025/01/02 15:19:13 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* key hook for WASD to move the player */
int	keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		cleanup(game);
		exit (0);
	}
	else if (keycode == 119 || keycode == 65362)
		move_player(game, -1, 0);
	else if (keycode == 115 || keycode == 65364)
		move_player(game, 1, 0);
	else if (keycode == 97 || keycode == 65361)
		move_player(game, 0, -1);
	else if (keycode == 100 || keycode == 65363)
		move_player(game, 0, 1);
	return (0);
}

/* click cross to close the win */
int	cross_close(t_game *game)
{
	(void)game;
	cleanup(game);
	exit(0);
}
