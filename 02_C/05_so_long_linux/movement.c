/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:26:19 by czhu              #+#    #+#             */
/*   Updated: 2025/01/02 15:28:30 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* cal player's new position */
void	cal_newposition(t_game *game, int *new_x, int *new_y)
{
	*new_x = game->player_x + game->dx;
	*new_y = game->player_y + game->dy;
}

/* validate the move:
    within the map range, positive, not wall */
int	validate_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= game->map_height
		|| new_y >= game->map_width)
		return (0);
	if (game->map[new_x][new_y] == '1')
		return (0);
	return (1);
}

/* handle collectibles & exit */
void	handle_interactions(t_game *game, int new_x, int new_y)
{
	if (game->map[new_x][new_y] == 'C')
	{
		game->collectibles--;
		game->map[new_x][new_y] = '0';
	}
	if (game->map[new_x][new_y] == 'E')
	{
		if (game->collectibles == 0)
		{
			ft_printf("You eat all the donuts!\n");
			cleanup(game);
			exit(0);
		}
		else
		{
			ft_printf("You need to collect all the donuts first!\n");
			return ;
		}
	}
}

/* update the game state*/
void	update_gamestate(t_game *game, int new_x, int new_y)
{
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Number of moves: %d\n", game->moves);
	render_frame(game);
}

/* move the player position based on key event */
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	game->dx = dx;
	game->dy = dy;
	cal_newposition(game, &new_x, &new_y);
	if (validate_move(game, new_x, new_y) == 0)
		return ;
	handle_interactions(game, new_x, new_y);
	update_gamestate(game, new_x, new_y);
}
