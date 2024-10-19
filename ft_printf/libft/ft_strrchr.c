/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:51:08 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 10:55:26 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	s += len;
	while (len > 0 && *s != (unsigned char)c)
	{
		s--;
		len--;
	}
	if (!len && *s != (unsigned char)c)
		return (0);
	return (s);
}
