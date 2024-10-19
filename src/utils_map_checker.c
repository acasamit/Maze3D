/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:33:11 by vcornill          #+#    #+#             */
/*   Updated: 2024/03/19 17:13:08 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	valid_ext(char *str)
{
	int	i;

	i = ft_strlen(str);
	i -= ft_strlen(".cub");
	if (i <= 0)
		return (0);
	return (!ft_strcmp(".cub", str + i));
}

int	is_closed(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("0NEWSD", map[i][j]) && (!map[i + 1] || i == 0))
				return (0);
			if (ft_strchr("0NEWSD", map[i][j]) && (!map[i][j + 1] || j == 0))
				return (0);
			if (ft_strchr("0NEWSD", map[i][j])
				&& (int)ft_strlen(map[i + 1]) - 1 < j)
				return (0);
			if (ft_strchr("0NEWSD", map[i][j])
				&& (!ft_strchr("10NEWSD", map[i][j + 1])
				|| !ft_strchr("10NEWSD", map[i][j - 1])
				|| !ft_strchr("10NEWSD", map[i + 1][j])
				|| !ft_strchr("10NEWSD", map[i - 1][j])))
				return (0);
		}
	}
	return (1);
}

int	forbidden_character(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i] && ft_strchr("\n", map[i][0]))
		continue ;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (!ft_strchr("10NEWSD ", map[i][j]))
				return (0);
	}
	return (1);
}

int	wrong_starting_pos(char **map)
{
	int	i;
	int	j;
	int	starting_pos;

	i = -1;
	starting_pos = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (ft_strchr("NEWS", map[i][j]))
				starting_pos++;
	}
	return (starting_pos != 1);
}

void	is_valid_map(t_game **game)
{
	if (!(*game)->map)
		ft_free_exit(*game, "Map is a directory/ empty.");
	if (!forbidden_character((*game)->map))
		ft_free_exit(*game, "Map contains forbidden characters.");
	if (!is_closed((*game)->map))
		ft_free_exit(*game, "Map is a not closed.");
	if (wrong_starting_pos((*game)->map))
		ft_free_exit(*game, "Wrong starting position.");
}
