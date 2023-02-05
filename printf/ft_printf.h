/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:24:37 by mfadil            #+#    #+#             */
/*   Updated: 2022/11/12 17:39:10 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>
# include<stdint.h>

void	ft_unsigned_putnbr(unsigned int c, int *l);
void	ft_putchar(const char c, int *l);
void	ft_putstr(const char *s, int *l);
void	ft_putnbr(int nb, int *l);
void	putnbr_lhexa(unsigned int nb, int *l);
void	putnbr_uhexa(unsigned int nb, int *l);
void	ft_pointer(unsigned long long nb, int *l);
void	ft_write_percent(const char c);
int		ft_printf(const char *str, ...);

#endif
