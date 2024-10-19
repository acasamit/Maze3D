/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:56:02 by vcornill          #+#    #+#             */
/*   Updated: 2024/03/14 15:44:24 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	valid_color_setting(char *setting)
{
	int	i;
	int	coma_flag;

	coma_flag = 0;
	i = 0;
	while (setting[i] && setting[i] != '\n')
	{
		while (setting[i] && setting[i] == ' ')
			i++;
		if (!ft_isdigit(setting[i]) && setting[i] != ' ')
			return (0);
		if (ft_atoi(&setting[i]) > 255 && setting[i] != ' ')
			return (0);
		while (ft_isdigit(setting[i]) || setting[i] == ' ')
			i++;
		if (setting[i] != ',' && coma_flag < 2)
			return (0);
		else
			coma_flag++;
		i++;
	}
	return (1);
}

void	add_color(t_game **game, char *color, char id)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)ft_atoi(color);
	while (*color && *color != ',')
		color++;
	color++;
	g = (unsigned char)ft_atoi(color);
	while (*color && *color != ',')
		color++;
	color++;
	b = (unsigned char)ft_atoi(color);
	if (id == 'C')
		(*game)->color_c
			= (unsigned int)((r << 24) | (g << 16) | (b << 8) | 255);
	else
		(*game)->color_f
			= (unsigned int)((r << 24) | (g << 16) | (b << 8) | 255);
}

void	valid_color(t_game **game, char *line)
{
	int		i;
	int		j;
	int		k;
	char	*id[3];

	id[0] = "F  ";
	id[1] = "C  ";
	i = -1;
	while (++i < 2)
	{
		j = -1;
		k = -1;
		while (line[++k] && line[k] == ' ')
			continue ;
		while (id[i][++j] && line && j < 2)
			if (id[i][j] != line[k++])
				break ;
		if (j == 2)
			break ;
	}
	if (i == 2)
		ft_free_exit(*game, "Color ID invalid/ Wrong parameter.");
	if (!valid_color_setting(&line[k]))
		ft_free_exit(*game, "Color instruction invalid.");
	update_bool(game, id[i]);
}
