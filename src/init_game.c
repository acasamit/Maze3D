/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:31:34 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/27 10:32:42 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate_left(t_game *game, double rotation_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_pos.x;
	old_plane_x = game->plane_pos.x;
	game->dir_pos.x = game->dir_pos.x * cos(rotation_angle) - game->dir_pos.y
		* sin(rotation_angle);
	game->dir_pos.y = old_dir_x * sin(rotation_angle) + game->dir_pos.y
		* cos(rotation_angle);
	game->plane_pos.x = game->plane_pos.x * cos(rotation_angle)
		- game->plane_pos.y * sin(rotation_angle);
	game->plane_pos.y = old_plane_x * sin(rotation_angle) + game->plane_pos.y
		* cos(rotation_angle);
}

void	rotate_right(t_game *game, double rotation_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_pos.x;
	old_plane_x = game->plane_pos.x;
	game->dir_pos.x = game->dir_pos.x * cos(-rotation_angle) - game->dir_pos.y
		* sin(-rotation_angle);
	game->dir_pos.y = old_dir_x * sin(-rotation_angle) + game->dir_pos.y
		* cos(-rotation_angle);
	game->plane_pos.x = game->plane_pos.x * cos(-rotation_angle)
		- game->plane_pos.y * sin(-rotation_angle);
	game->plane_pos.y = old_plane_x * sin(-rotation_angle) + game->plane_pos.y
		* cos(-rotation_angle);
}

void	set_dir_pos(t_game *game)
{
	if (game->starting_dir == 'W')
		rotate_right(game, M_PI);
	if (game->starting_dir == 'N')
		rotate_right(game, M_PI / 2);
	if (game->starting_dir == 'S')
		rotate_left(game, M_PI / 2);
}

void	init_raycasting(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->dir_pos.x = 0.4999;
	game->dir_pos.y = 0;
	game->plane_pos.x = 0;
	game->plane_pos.y = 0.66;
	set_dir_pos(game);
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == ' '
				|| (game->map[i][j] >= '\t' && game->map[i][j] <= '\r'))
				game->map[i][j] = '1';
	}
}

void	init_game(t_game *game)
{
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	init_raycasting(game);
	game->no = 0;
	game->so = 0;
	game->we = 0;
	game->ea = 0;
}
