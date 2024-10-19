/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:35:45 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/24 15:03:49 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	c_print(char ap, int *i);
void	ft_putnbr_base(unsigned long long int nbr, char *base, int *nbchar);
void	ft_putptr(void *ptr, int *nbchar);
void	i_print(long int n, int *i);
void	per_print(int *i);
void	s_print(char *ap, int *i);
void	u_print(unsigned int ap, int *i);
void	x_print(long long int ap, int *i);
void	xx_print(long long int ap, int *i);

#endif
