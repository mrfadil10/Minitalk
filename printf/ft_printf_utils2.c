/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:27:20 by mfadil            #+#    #+#             */
/*   Updated: 2022/11/12 17:37:09 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c, int *l)
{
	*l += write (1, &c, 1);
}

void	putnbr_lhexa(unsigned int nb, int *l)
{
	char	*s;

	s = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(s[nb % 16], l);
	else
	{
		putnbr_lhexa((nb / 16), l);
		ft_putchar(s[nb % 16], l);
	}
}

void	putnbr_uhexa(unsigned int nb, int *l)
{
	char	*s;

	s = "0123456789ABCDEF";
	if (nb < 16)
		ft_putchar(s[nb % 16], l);
	else
	{
		putnbr_uhexa((nb / 16), l);
		ft_putchar(s[nb % 16], l);
	}
}

static void	putnbr_xa(unsigned long long nb, int *l)
{
	char	*s;

	s = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(s[nb % 16], l);
	else
	{
		putnbr_xa((nb / 16), l);
		ft_putchar(s[nb % 16], l);
	}
}

void	ft_pointer(unsigned long long nb, int *l)
{
	ft_putstr("0x", l);
	putnbr_xa(nb, l);
}
