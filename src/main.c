/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:34:38 by acasamit          #+#    #+#             */
/*   Updated: 2024/03/15 17:57:05 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	escape(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	parsing(&game, argc, argv);
	game->main_img = NULL;
	init_game(game);
	mlx_loop_hook(game->mlx, escape, game);
	mlx_loop_hook(game->mlx, raycast, game);
	mlx_loop_hook(game->mlx, handle_w_s, game);
	mlx_loop_hook(game->mlx, handle_right_rotation, game);
	mlx_loop_hook(game->mlx, handle_left_rotation, game);
	mlx_loop_hook(game->mlx, handle_straf, game);
	mlx_loop(game->mlx);
	free_game(game);
	return (0);
}
