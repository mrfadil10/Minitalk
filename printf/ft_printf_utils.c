/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:29:49 by mfadil            #+#    #+#             */
/*   Updated: 2022/11/12 10:47:31 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *s, int *l)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i], l);
		i++;
	}
}

void	ft_putnbr(int nb, int *l)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2", l);
		ft_putstr("147483648", l);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', l);
		nb = nb * (-1);
	}
	if (nb < 10)
		ft_putchar(nb + '0', l);
	else
	{
		ft_putnbr(nb / 10, l);
		ft_putnbr(nb % 10, l);
	}
}

void	ft_unsigned_putnbr(unsigned int nb, int *l)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0', l);
	}
	else
	{
		ft_unsigned_putnbr(nb / 10, l);
		ft_unsigned_putnbr(nb % 10, l);
	}
}
