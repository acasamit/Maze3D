/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:02:11 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/16 18:02:14 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	overlap(void *dest, void *src, int n)
{
	int		overlapping;
	void	*src_end;

	src_end = src + n;
	overlapping = 0;
	if (dest >= src && dest < src_end)
		overlapping = 1;
	return (overlapping);
}

void	*ft_memmove(void *dest, void *src, int n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (dest);
	if (overlap(dest, src, n))
		while (n-- > 0)
			d[n] = s[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
