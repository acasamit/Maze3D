/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:25:19 by acasamit          #+#    #+#             */
/*   Updated: 2024/02/23 02:25:31 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_raycast	rc_init(t_game *game, int x)
{
	t_raycast	raycast;

	raycast.camerax = 2 * x / (double)WIDTH - 1;
	raycast.raydirx = game->dir_pos.x + game->plane_pos.x * raycast.camerax;
	raycast.raydiry = game->dir_pos.y + game->plane_pos.y * raycast.camerax;
	raycast.mapx = (int)game->player_pos.x;
	raycast.mapy = (int)game->player_pos.y;
	if (raycast.raydirx == 0)
		raycast.deltadistx = 1e30;
	else
		raycast.deltadistx = fabs(1 / raycast.raydirx);
	if (raycast.raydiry == 0)
		raycast.deltadisty = 1e30;
	else
		raycast.deltadisty = fabs(1 / raycast.raydiry);
	raycast.hit = 0;
	return (raycast);
}

t_raycast	is_hit(t_raycast raycast, t_game *game)
{
	while (raycast.hit == 0)
	{
		if (raycast.sidedistx < raycast.sidedisty)
		{
			raycast.sidedistx += raycast.deltadistx;
			raycast.mapx += raycast.stepx;
			raycast.side = 0;
		}
		else
		{
			raycast.sidedisty += raycast.deltadisty;
			raycast.mapy += raycast.stepy;
			raycast.side = 1;
		}
		if (game->map[raycast.mapy][raycast.mapx] > '0')
			raycast.hit = 1;
	}
	if (raycast.side == 0)
		raycast.perpwalldist = (raycast.sidedistx - raycast.deltadistx);
	else
		raycast.perpwalldist = (raycast.sidedisty - raycast.deltadisty);
	return (raycast);
}

t_raycast	set_step_y(t_raycast raycast, t_game *game)
{
	if (raycast.raydiry < 0)
	{
		raycast.stepy = -1;
		raycast.sidedisty = (game->player_pos.y - raycast.mapy)
			* raycast.deltadisty;
	}
	else
	{
		raycast.stepy = 1;
		raycast.sidedisty = (raycast.mapy + 1.0 - game->player_pos.y)
			* raycast.deltadisty;
	}
	return (raycast);
}

t_raycast	set_side_dist(t_game *game, int x)
{
	t_raycast	raycast;

	raycast = rc_init(game, x);
	if (raycast.raydirx < 0)
	{
		raycast.stepx = -1;
		raycast.sidedistx = (game->player_pos.x - raycast.mapx)
			* raycast.deltadistx;
	}
	else
	{
		raycast.stepx = 1;
		raycast.sidedistx = (raycast.mapx + 1.0 - game->player_pos.x)
			* raycast.deltadistx;
	}
	raycast = set_step_y(raycast, game);
	raycast = is_hit(raycast, game);
	return (raycast);
}

void	raycast(void *param)
{
	t_game		*game;
	t_raycast	raycast;
	int			x;

	x = -1;
	game = (t_game *)param;
	if (game->main_img)
		mlx_delete_image(game->mlx, game->main_img);
	game->main_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	while (++x < WIDTH)
	{
		raycast = set_side_dist(game, x);
		raycast.lineheight = (int)(HEIGHT / raycast.perpwalldist);
		raycast.drawstart = -raycast.lineheight / 2 + HEIGHT / 2;
		if (raycast.drawstart < 0)
			raycast.drawstart = 0;
		raycast.drawend = raycast.lineheight / 2 + HEIGHT / 2;
		if (raycast.drawend >= HEIGHT)
			raycast.drawend = HEIGHT;
		draw_image(game, raycast, x);
	}
	mlx_image_to_window(game->mlx, game->main_img, 0, 0);
}
