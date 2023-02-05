/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:29:38 by mfadil            #+#    #+#             */
/*   Updated: 2022/11/12 17:45:09 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_formats(const char *p, int i, va_list ap, int *lnt)
{
	if (p[i] == 'c')
		ft_putchar(va_arg(ap, int), lnt);
	else if (p[i] == 's')
		ft_putstr(va_arg(ap, char *), lnt);
	else if (p[i] == 'p')
		ft_pointer(va_arg(ap, unsigned long long), lnt);
	else if (p[i] == 'd' || p[i] == 'i')
		ft_putnbr(va_arg(ap, int), lnt);
	else if (p[i] == 'u')
		ft_unsigned_putnbr(va_arg(ap, unsigned int), lnt);
	else if (p[i] == 'x')
		putnbr_lhexa(va_arg(ap, unsigned int), lnt);
	else if (p[i] == 'X')
		putnbr_uhexa(va_arg(ap, unsigned int), lnt);
	else if (p[i] == '%')
		ft_putchar(p[i], lnt);
	else
		ft_putchar(p[i], lnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		lnt;

	i = 0;
	lnt = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_formats(format, i, args, &lnt);
		}
		else
			ft_putchar(format[i], &lnt);
		i++;
	}
	va_end(args);
	if (lnt < 0)
		return (-1);
	return (lnt);
}
