/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:23:48 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/17 16:41:10 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*int_min(void)
{
	char	*min;

	min = malloc(12);
	if (!min)
		return (NULL);
	ft_strlcpy(min, "-2147483648", 12);
	return (min);
}

int	negneg(int n, int *neg)
{
	if (n < 0)
	{
		*neg = 1;
		return (-n);
	}
	*neg = 0;
	return (n);
}

int	testtest(int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		i;
	char	*nb;

	if (n == -2147483648)
		return (int_min());
	n = negneg(n, &neg);
	i = testtest(n);
	nb = malloc(i + 1 + neg);
	if (!nb)
		return (0);
	if (neg)
		nb[0] = '-';
	nb[i + neg] = '\0';
	while (i-- > 0)
	{
		nb[i + neg] = n % 10 + '0';
		n /= 10;
	}
	return (nb);
}
