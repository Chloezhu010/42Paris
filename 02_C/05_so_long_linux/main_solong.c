/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_solong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:40:38 by czhu              #+#    #+#             */
/*   Updated: 2025/01/02 15:37:18 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* main function */
void	check_helper(t_game *game)
{
	if (validate_map(game) == 0)
	{
		ft_printf("Error\nThe map is invalid\n");
		cleanup(game);
		exit (1);
	}
	if (!check_item(game))
	{
		ft_printf("Error\nInvalid map items\n");
		cleanup(game);
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error\nNeed a map input\n");
		exit (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!parse_map(&game, av[1]))
	{
		ft_printf("Error\nFail to parse the map\n");
		cleanup(&game);
		exit (1);
	}
	check_helper(&game);
	init_game(&game);
	player_pos(&game, &game.player_x, &game.player_y);
	mlx_key_hook(game.win, keypress, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_hook(game.win, 17, 0, cross_close, &game);
	mlx_loop(game.mlx);
	cleanup(&game);
	return (0);
}
