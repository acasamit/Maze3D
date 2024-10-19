/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:58:05 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/31 16:13:23 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_lines(char *lines)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (lines[i] && lines[i] != '\n')
		i++;
	if (!lines[i])
	{
		free(lines);
		return (NULL);
	}
	next = malloc(gnl_strlen(lines) - i + 1);
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (lines[i])
		next[j++] = lines[i++];
	next[j] = '\0';
	free(lines);
	return (next);
}

char	*get_the_line(char *lines)
{
	char	*my_line;
	int		i;

	if (!lines[0])
		return (NULL);
	i = 0;
	while (lines[i] && lines[i] != '\n')
		i++;
	my_line = (char *)malloc(i + 2);
	if (!my_line)
		return (NULL);
	i = 0;
	while (lines[i] && lines[i] != '\n')
	{
		my_line[i] = lines[i];
		i++;
	}
	if (lines[i] == '\n')
	{
		my_line[i] = '\n';
		i++;
	}
	my_line[i] = '\0';
	return (my_line);
}

char	*ft_read_lines(int fd, char *lines)
{
	int		chr_read;
	char	*buffer;

	chr_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (chr_read != 0 && !gnl_strchr(lines, '\n'))
	{
		chr_read = read(fd, buffer, BUFFER_SIZE);
		if (chr_read == -1)
		{
			free(buffer);
			free(lines);
			return (NULL);
		}
		buffer[chr_read] = '\0';
		lines = gnl_strjoin(lines, buffer);
	}
	free(buffer);
	return (lines);
}

char	*get_next_line(int fd)
{
	static char	*lines[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines[fd] = ft_read_lines(fd, lines[fd]);
	if (!lines[fd])
		return (NULL);
	line = get_the_line(lines[fd]);
	lines[fd] = ft_next_lines(lines[fd]);
	return (line);
}
