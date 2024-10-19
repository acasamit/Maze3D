/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:16:19 by vcornill          #+#    #+#             */
/*   Updated: 2023/08/17 13:33:02 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*tampon;

	i = ft_strlen(src);
	tampon = malloc(i + 1);
	if (tampon == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		tampon[i] = src[i];
	tampon[i] = '\0';
	return (tampon);
}
