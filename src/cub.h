/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:07:23 by acasamit          #+#    #+#             */
/*   Updated: 2024/03/15 16:49:12 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_printf.h"
#include "MLX42.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

#define WIDTH	1920
#define HEIGHT	1080
#define TEXTUREWIDTH	512
#define TEXTUREHEIGHT	512

typedef struct s_coord
{
	double	x;
	double	y;
}		t_coord;

typedef struct s_int_coord
{
	int	x;
	int	y;
}		t_int_coord;

typedef struct s_game
{
	char			**instructions;
	char			**map;
	t_coord			player_pos;
	t_coord			plane_pos;
	t_coord			dir_pos;
	t_int_coord		cell;
	t_int_coord		texture_floor;
	t_coord			ray0;
	t_coord			ray1;
	t_coord			floor_step;
	t_coord			floor;
	int				p;
	float			pos_z;
	float			row_distance;
	int				starting_dir;
	mlx_t			*mlx;
	mlx_texture_t	*tab_texture[4];
	mlx_image_t		*main_img;
	int				f;
	int				c;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				color_c;
	int				color_f;
	uint32_t		buffer[WIDTH][HEIGHT];
}	t_game;

typedef struct s_raycast
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	step;
	double	wallx;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	int		tex_y;
}	t_raycast;

// Error
void		ft_exit(char *str);
void		free_game(t_game *game);
void		ft_free_exit(t_game *game, char *str);

// Utils general
void		ft_free_tab(char **tab);
int			only_w_spaces(char *str);

// Parsing
void		parsing(t_game **game, int argc, char **argv);

// Utils parsing
int			check_format(char *str, char *cmp);
int			is_map(t_game *game, char *line);
char		**add_line(char **tab, char *line);
void		valid_instruction(t_game **game, char *line);
void		valid_color(t_game **game, char *line);
void		is_valid_map(t_game **game);
void		update_bool(t_game **game, char *id);
void		add_color(t_game **game, char *color, char id);
void		valid_color(t_game **game, char *line);
void		init_game_ptr(t_game **game);

// Init game
void		init_game(t_game *game);

// Keys
void		handle_w_s(void *param);
void		handle_left_rotation(void *param);
void		handle_right_rotation(void *param);
void		handle_straf(void *param);

// draw
int			get_rgba(int r, int g, int b, int a);
t_raycast	put_pixel(t_raycast raycast, t_game *game, double tex_x, int x);
t_raycast	texture_writter(t_game *game, t_raycast raycast, int x);
void		floor_and_celling_writter(t_raycast raycast, t_game *game, int x);
void		draw_image(t_game *game, t_raycast raycast, int x);

// raycast
void		raycast(void *param);
t_raycast	set_side_dist(t_game *game, int x);
t_raycast	set_step_y(t_raycast raycast, t_game *game);
t_raycast	is_hit(t_raycast raycast, t_game *game);
t_raycast	rc_init(t_game *game, int x);
