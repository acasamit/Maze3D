/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:12:55 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 11:36:46 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lillen;

	lillen = ft_strlen(little);
	i = -1;
	if (!little || !*little)
		return ((char *)big);
	while (big[++i] && i < len)
	{
		j = 0;
		while (little[j] && big[j + i] && j + i < len)
		{
			if (little[j] != big[j + i])
				break ;
			j++;
		}
		if (lillen == j)
			return ((char *)big + i);
	}
	return (0);
}
