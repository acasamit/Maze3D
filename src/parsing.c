/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:33:31 by vcornill          #+#    #+#             */
/*   Updated: 2024/03/19 17:17:43 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		ft_exit("Wrong number of argument.");
	if (!check_format(argv[1], ".cub"))
		ft_exit("Wrong format");
}

void	fill_tabs(t_game **game, char *file_name)
{
	char	*line;
	int		fd;
	int		flag;

	flag = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_free_exit(*game, "File could not be opened.");
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_map(*game, line))
		{
			if (!only_w_spaces(line))
				flag = 1;
			if (flag)
				(*game)->map = add_line((*game)->map, line);
		}
		else if (!flag && !only_w_spaces(line))
			(*game)->instructions = add_line((*game)->instructions, line);
		free(line);
	}
	close(fd);
}

void	check_tabs(t_game **game)
{
	int	tab_size;

	is_valid_map(game);
	tab_size = -1;
	while ((*game)->instructions && (*game)->instructions[++tab_size])
	{
		if (tab_size == 0)
			valid_instruction(game, (*game)->instructions[tab_size]);
		else if (tab_size == 1)
			valid_instruction(game, (*game)->instructions[tab_size]);
		else if (tab_size == 2)
			valid_instruction(game, (*game)->instructions[tab_size]);
		else if (tab_size == 3)
			valid_instruction(game, (*game)->instructions[tab_size]);
		else if (tab_size == 4)
			valid_instruction(game, (*game)->instructions[tab_size]);
		else if (tab_size == 5)
			valid_instruction(game, (*game)->instructions[tab_size]);
	}
	if (tab_size != 6)
		ft_free_exit(*game, "Wrong number of instructions.");
}

void	init_player_pos(t_game **game)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = -1;
	while ((*game)->map[++i])
	{
		j = -1;
		while ((*game)->map[i][++j])
		{
			if (((*game)->map[i][j] == 'N') || ((*game)->map[i][j] == 'W')
				|| ((*game)->map[i][j] == 'E') || ((*game)->map[i][j] == 'S'))
			{
				found = 1;
				(*game)->player_pos.x = j + 0.5;
				(*game)->player_pos.y = i + 0.5;
				(*game)->starting_dir = (*game)->map[i][j];
				(*game)->map[i][j] = '0';
				break ;
			}
		}
		if (found)
			break ;
	}
}

void	parsing(t_game **game, int argc, char **argv)
{
	check_args(argc, argv);
	init_game_ptr(game);
	fill_tabs(game, argv[1]);
	check_tabs(game);
	init_player_pos(game);
}
