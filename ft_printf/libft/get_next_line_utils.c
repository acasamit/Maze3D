/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:04:00 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/30 13:09:36 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		continue ;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*conca;
	int		i;
	int		len;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = gnl_strlen(s1) + gnl_strlen(s2);
	conca = malloc(len + 1);
	if (!conca)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		conca[i] = s1[i];
	while (s2[++j])
		conca[i + j] = s2[j];
	conca[len] = '\0';
	free(s1);
	return (conca);
}

char	*gnl_strchr(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	while (*s != (unsigned char)c && *s)
		s++;
	if (*s != (unsigned char)c)
		return (0);
	return (s);
}
