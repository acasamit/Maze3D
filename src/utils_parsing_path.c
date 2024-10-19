/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:56:05 by vcornill          #+#    #+#             */
/*   Updated: 2024/03/15 18:23:59 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	valid_path(char *path, t_game **game, int indexText)
{
	int		i;
	char	*str;

	i = -1;
	str = ft_strtrim(path, "\n ");
	(*game)->tab_texture[indexText] = mlx_load_png(str);
	free(str);
	if (!(*game)->tab_texture[indexText])
		return (0);
	return ((*game)->no);
}

int	check_id(char *line, t_game **game, int i)
{
	char	*tab[4];
	int		j;
	int		k;

	tab[0] = "NO ";
	tab[1] = "SO ";
	tab[2] = "WE ";
	tab[3] = "EA ";
	while (++i < 4)
	{
		k = 0;
		while (line[k] && line[k] == ' ')
			k++;
		j = -1;
		while (tab[i][++j] && line && j < 3)
			if (tab[i][j] != line[k++])
				break ;
		if (j == 3)
			break ;
	}
	if (i == 4)
		return (1);
	else
		update_bool(game, tab[i]);
	return (0);
}

void	update_bool(t_game **game, char *id)
{
	if (ft_strcmp(id, "NO ") == 0)
		(*game)->no += 1;
	else if (ft_strcmp(id, "SO ") == 0)
		(*game)->so += 1;
	else if (ft_strcmp(id, "WE ") == 0)
		(*game)->we += 1;
	else if (ft_strcmp(id, "EA ") == 0)
		(*game)->ea += 1;
	else if (ft_strcmp(id, "F  ") == 0)
		(*game)->f += 1;
	else if (ft_strcmp(id, "C  ") == 0)
		(*game)->c += 1;
	if ((*game)->no > 1 || (*game)->so > 1
		|| (*game)->we > 1
		|| (*game)->ea > 1
		|| (*game)->f > 1
		|| (*game)->c > 1)
		ft_free_exit(*game, "Instruction parameter exists more than once.");
}

int	get_id(char *line)
{
	int		i;

	i = -1;
	while (line[++i] && line[i] == ' ')
		continue ;
	if (line[i] == 'N')
		return (0);
	else if (line[i] == 'S')
		return (1);
	else if (line[i] == 'E')
		return (2);
	else
		return (3);
}

void	valid_instruction(t_game **game, char *line)
{
	int			i;

	i = -1;
	while (line[++i] && line[i] == ' ')
		continue ;
	if (!check_id(line, game, -1))
	{
		if (!valid_path(&line[i + 2], game, get_id(line)))
			ft_free_exit(*game, "Instruction path invalid.");
	}
	else
	{
		valid_color(game, line);
		add_color(game, &line[i + 1], line[0]);
	}
}
