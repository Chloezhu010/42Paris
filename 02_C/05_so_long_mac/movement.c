/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:26:19 by czhu              #+#    #+#             */
/*   Updated: 2024/12/30 15:33:47 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* to printout messages */
void    write_message(char *message)
{
    write(1, message, ft_strlen(message));
}

/* cal player's new position */
void    cal_newposition(t_game *game, int dx, int dy, int *new_x, int *new_y)
{
    *new_x = game->player_x + dx;
    *new_y = game->player_y + dy;
}

/* validate the move:
    within the map range, positive, not wall */
int validate_move(t_game *game, int new_x, int new_y)
{
    // out of map scope
    if (new_x < 0 || new_y < 0 || new_x >= game->map_height || new_y >= game->map_width)
        return (0);
    // reach the wall
    if (game->map[new_x][new_y] == '1')
        return (0);
    return (1);
}

/* handle collectibles & exit */
void    handle_interactions(t_game *game, int new_x, int new_y)
{
    // handle collectibles
    if (game->map[new_x][new_y] == 'C')
    {
        game->collectibles --;
        game->map[new_x][new_y] = '0'; // remove the collectible
    }
    // handle exit
    if (game->map[new_x][new_y] == 'E')
    {
        if (game->collectibles == 0)
        {
            write_message("You win!\n");
            mlx_destroy_window(game->mlx, game->win);
            exit(0);
        }
        else
        {
            write_message("You need to collect all the sweeties first!\n");
            return ;
        }
    }
}

/* update the game state*/
void    update_gamestate(t_game *game, int new_x, int new_y)
{
    game->player_x = new_x;
    game->player_y = new_y;
    game->moves++;
    render_frame(game);
}

/* move the player position based on key event */
void    move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

    cal_newposition(game, dx, dy, &new_x, &new_y);
    if (validate_move(game, new_x, new_y) == 0)
        return ;
    handle_interactions(game, new_x, new_y);
    update_gamestate(game, new_x, new_y);
}

/* key hook for WASD to move the player */
int	keypress(int keycode, t_game *game)
{
    if (keycode == 53)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    else if (keycode == 13) // W or Up arrow
        move_player(game, -1, 0);
    else if (keycode == 1) // S or Down arrow
        move_player(game, 1, 0);
    else if (keycode == 0) // A or Left arrow
        move_player(game, 0, -1);
    else if (keycode == 2) // D or Right arrow
        move_player(game, 0, 1);
    return (0);
}

/* click cross to close the win */
int cross_close(t_game *game)
{
    (void)game;
    exit(0);
}
