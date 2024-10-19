/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:38:10 by vcornill          #+#    #+#             */
/*   Updated: 2024/03/19 17:17:49 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_game_ptr(t_game **game)
{
	int	i;

	*game = ft_calloc(1, sizeof(t_game));
	(*game)->map = NULL;
	(*game)->instructions = NULL;
	(*game)->mlx = mlx_init(WIDTH, HEIGHT, "BackRoom", 1);
	i = -1;
	while (++i < 4)
		(*game)->tab_texture[i] = NULL;
}

int	check_format(char *str, char *cmp)
{
	int	i;

	i = 0;
	while (str[i] && ft_strcmp(&str[i], cmp) != 0)
		i++;
	if (ft_strcmp(&str[i], cmp) == 0)
		return (1);
	return (0);
}

int	is_map(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] == 'N' || line[i] == 'E'
		|| line[i] == 'S' || line[i] == 'W'
		|| line[i] == 'C' || line[i] == 'F')
		return (0);
	line--;
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != '\n'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\t')
			ft_free_exit(game, "Forbidden char in map.");
		if (line[i + 1] && line[i + 1] == '\n')
			line[i + 1] = '\0';
	}
	return (1);
}

char	**add_line(char **tab, char *line)
{
	char	**newtab;
	int		tab_size;
	int		i;

	tab_size = 1;
	while (tab && tab[tab_size])
		tab_size++;
	newtab = ft_calloc(tab_size + 2, sizeof(char *));
	i = -1;
	while (++i < tab_size && tab)
		newtab[i] = ft_strdup(tab[i]);
	newtab[i] = ft_strdup(line);
	newtab[++i] = NULL;
	ft_free_tab(tab);
	return (newtab);
}
