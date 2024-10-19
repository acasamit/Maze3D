/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:22:10 by acasamit          #+#    #+#             */
/*   Updated: 2024/02/23 02:27:17 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_raycast	put_pixel(t_raycast raycast, t_game *game, double tex_x, int x)
{
	int		y;
	uint8_t	*color;
	double	texpos;

	y = raycast.drawstart - 1;
	texpos = (raycast.drawstart - HEIGHT / 2 + raycast.lineheight / 2)
		* raycast.step;
	while (++y < raycast.drawend)
	{
		raycast.tex_y = (int)texpos & (TEXTUREHEIGHT - 1);
		texpos += raycast.step;
		color = &game->tab_texture[raycast.texnum]->pixels
		[(int)((TEXTUREHEIGHT * raycast.tex_y + tex_x) * 4)];
		mlx_put_pixel(game->main_img, x, y, get_rgba(color[0],
				color[1], color[2], color[3]));
	}
	return (raycast);
}

t_raycast	texture_writter(t_game *game, t_raycast raycast, int x)
{
	int		tex_x;

	if (raycast.side == 0)
		raycast.wallx = game->player_pos.y + raycast.perpwalldist
			* raycast.raydiry;
	else
		raycast.wallx = game->player_pos.x + raycast.perpwalldist
			* raycast.raydirx;
	raycast.wallx -= floor((raycast.wallx));
	tex_x = (int)(raycast.wallx * (double)TEXTUREWIDTH);
	if (raycast.side == 0 && raycast.raydirx > 0)
		tex_x = TEXTUREWIDTH - tex_x - 1;
	if (raycast.side == 1 && raycast.raydiry < 0)
		tex_x = TEXTUREWIDTH - tex_x - 1;
	raycast.step = 1.0 * TEXTUREHEIGHT / raycast.lineheight;
	raycast = put_pixel(raycast, game, tex_x, x);
	return (raycast);
}

void	floor_and_celling_writter(t_raycast raycast, t_game *game, int x)
{
	int	yr;
	int	yf;

	yr = 0;
	yf = raycast.drawend;
	while (yr < raycast.drawstart)
	{
		mlx_put_pixel(game->main_img, x, yr, game->color_c);
		yr++;
	}
	while (yf < HEIGHT)
	{
		mlx_put_pixel(game->main_img, x, yf, game->color_f);
		yf++;
	}
}

void	draw_image(t_game *game, t_raycast raycast, int x)
{
	if (raycast.side == 0)
	{
		if (raycast.raydirx > 0)
			raycast.texnum = 3;
		else
			raycast.texnum = 1;
	}
	else
	{
		if (raycast.raydiry > 0)
			raycast.texnum = 2;
		else
			raycast.texnum = 0;
	}
	raycast = texture_writter(game, raycast, x);
	floor_and_celling_writter(raycast, game, x);
}
