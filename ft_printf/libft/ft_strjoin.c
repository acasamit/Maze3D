/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:17:19 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/18 10:17:20 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*conca;
	int		i;
	int		len;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	conca = malloc(len + 1);
	if (!conca)
		return (NULL);
	if (!s1 && !s2)
		return (0);
	i = -1;
	while (s1[++i])
		conca[i] = s1[i];
	j = -1;
	while (s2[++j])
		conca[j + i] = s2[j];
	conca[i + j] = '\0';
	return (conca);
}
