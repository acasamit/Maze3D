/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:16:25 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 15:39:22 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	char	*trimmed;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	if (end - start + 1 <= 0)
	{
		trimmed = (char *)malloc(1);
		if (trimmed)
			trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = (char *)malloc(end - start + 2);
	if (!trimmed)
		return (0);
	ft_strlcpy(trimmed, s1 + start, end - start + 2);
	return (trimmed);
}
