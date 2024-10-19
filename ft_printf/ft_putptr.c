/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:47:24 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/24 15:35:20 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int	viable_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i + 1] != '\0')
	{
		if ((base[i] >= 8 && base[i] <= 13) || base[i] == 32)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base [i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	recur_base(unsigned long int nbr, char *b, unsigned int sb, int *n)
{
	if (nbr >= sb)
		recur_base(nbr / sb, b, sb, n);
	ft_putchar(b[nbr % sb]);
	*n += 1;
}

void	ft_putnbr_base(unsigned long long int nbr, char *base, int *nbchar)
{
	unsigned long long int	size_base;
	unsigned long long int	nbrbis;

	nbrbis = nbr;
	size_base = ft_strlen(base);
	if (viable_base(base) == 0 || size_base <= 1)
		return ;
	recur_base(nbrbis, base, size_base, nbchar);
}

void	ft_putptr(void *ptr, int *nbchar)
{
	unsigned long long	address;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		*nbchar = *nbchar + 5;
		return ;
	}
	if (!ptr)
	{
		write(1, "(null)", 6);
		*nbchar = *nbchar + 6;
		return ;
	}
	address = (unsigned long long)ptr;
	ft_putstr_fd("0x", 1);
	*nbchar = *nbchar + 2;
	ft_putnbr_base(address, "0123456789abcdef", nbchar);
}
