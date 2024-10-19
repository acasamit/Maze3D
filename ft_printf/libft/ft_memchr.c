/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:57:55 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 11:36:20 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(void *s, int c, int n)
{
	unsigned char	*p;
	unsigned int	i;

	p = (unsigned char *)s;
	i = -1;
	while (++i < (unsigned int)n)
		if (p[i] == (unsigned char)c)
			return ((void *)&p[i]);
	return (0);
}
