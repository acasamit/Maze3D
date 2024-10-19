/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:25:16 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/24 15:37:40 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_test(va_list ap, int *i, int *j, const char *str)
{
	if (str[*j + 1] == 'c')
		c_print(va_arg(ap, int), i);
	else if (str[*j + 1] == 's')
		s_print(va_arg(ap, char *), i);
	else if (str[*j + 1] == 'p')
		ft_putptr(va_arg(ap, void *), i);
	else if (str[*j + 1] == 'i' || str[*j + 1] == 'd')
		i_print(va_arg(ap, int), i);
	else if (str[*j + 1] == 'u')
		u_print(va_arg(ap, unsigned int), i);
	else if (str[*j + 1] == 'x')
		x_print(va_arg(ap, long long int), i);
	else if (str[*j + 1] == 'X')
		xx_print(va_arg(ap, long long int), i);
	else if (str[*j + 1] == '%')
		per_print(i);
	else
	{
		write(1, &str[*j], 1);
		*j -= 1;
	}
	*j += 1;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		j;

	j = -1;
	i = 0;
	va_start(ap, str);
	while (str[++j])
	{
		if (str[j] != '%')
		{
			write(1, &str[j], 1);
			i++;
		}
		else
			p_test(ap, &i, &j, str);
	}
	va_end(ap);
	return (i);
}
/*
int	main()
{
	int	j;

        j = ft_printf("%p %p\n", 0, 0);
        ft_printf("%i\n",j);
	j = printf("%p %p\n", 0, 0);
	ft_printf("%i\n",j);
        j = ft_printf("%x\n", 2147483647);
	ft_printf("%i\n",j);
	j = printf("%x\n", 2147483647);
	ft_printf("%i\n",j);
	j = ft_printf("%X\n", 9223372036854775807LL);
	ft_printf("%i\n",j);
	j = printf("%X\n",9223372036854775807LL);
        ft_printf("%i\n",j);
	return 0;
}*/
