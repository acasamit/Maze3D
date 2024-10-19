/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:20:11 by acasamit          #+#    #+#             */
/*   Updated: 2024/02/23 02:28:49 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	handle_w_s(void *param)
{
	t_game	*game;
	double	move_speed;

	game = (t_game *)param;
	move_speed = 0.1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		if (game->map[(int)(game->player_pos.y)][(int)(game->player_pos.x
			+ game->dir_pos.x * move_speed)] == '0')
			game->player_pos.x += game->dir_pos.x * move_speed;
		if (game->map[(int)(game->player_pos.y + game->dir_pos.y
				* move_speed)][(int)game->player_pos.x] == '0')
			game->player_pos.y += game->dir_pos.y * move_speed;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		if (game->map[(int)(game->player_pos.y)][(int)(game->player_pos.x
			- game->dir_pos.x * move_speed)] == '0')
			game->player_pos.x -= game->dir_pos.x * move_speed;
		if (game->map[(int)(game->player_pos.y - game->dir_pos.y
				* move_speed)][(int)game->player_pos.x] == '0')
			game->player_pos.y -= game->dir_pos.y * move_speed;
	}
}

void	handle_right_rotation(void *param)
{
	t_game	*game;
	double	rot_speed;
	double	old_dirx;
	double	old_planex;

	game = (t_game *)param;
	rot_speed = 0.1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		old_dirx = game->dir_pos.x;
		game->dir_pos.x = game->dir_pos.x * cos(rot_speed)
			- game->dir_pos.y * sin(rot_speed);
		game->dir_pos.y = old_dirx * sin(rot_speed)
			+ game->dir_pos.y * cos(rot_speed);
		old_planex = game->plane_pos.x;
		game->plane_pos.x = game->plane_pos.x * cos(rot_speed)
			- game->plane_pos.y * sin(rot_speed);
		game->plane_pos.y = old_planex * sin(rot_speed)
			+ game->plane_pos.y * cos(rot_speed);
	}
}

void	handle_left_rotation(void *param)
{
	t_game	*game;
	double	rot_speed;
	double	old_dirx;
	double	old_planex;

	game = (t_game *)param;
	rot_speed = 0.1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		old_dirx = game->dir_pos.x;
		game->dir_pos.x = game->dir_pos.x * cos(-rot_speed)
			- game->dir_pos.y * sin(-rot_speed);
		game->dir_pos.y = old_dirx * sin(-rot_speed)
			+ game->dir_pos.y * cos(-rot_speed);
		old_planex = game->plane_pos.x;
		game->plane_pos.x = game->plane_pos.x * cos(-rot_speed)
			- game->plane_pos.y * sin(-rot_speed);
		game->plane_pos.y = old_planex * sin(-rot_speed)
			+ game->plane_pos.y * cos(-rot_speed);
	}
}

void	handle_straf(void *param)
{
	t_game	*game;
	double	move_speed;

	game = (t_game *)param;
	move_speed = 0.05;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		if (game->map[(int)(game->player_pos.y + game->plane_pos.y
				* move_speed)][(int)game->player_pos.x] == '0')
			game->player_pos.y += game->plane_pos.y * move_speed;
		if (game->map[(int)game->player_pos.y][(int)(game->player_pos.x
			+ game->plane_pos.x * move_speed)] == '0')
			game->player_pos.x += game->plane_pos.x * move_speed;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		if (game->map[(int)(game->player_pos.y - game->plane_pos.y
				* move_speed)][(int)game->player_pos.x] == '0')
			game->player_pos.y -= game->plane_pos.y * move_speed;
		if (game->map[(int)game->player_pos.y][(int)(game->player_pos.x
			- game->plane_pos.x * move_speed)] == '0')
			game->player_pos.x -= game->plane_pos.x * move_speed;
	}
}
