/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:21:14 by mfadil            #+#    #+#             */
/*   Updated: 2023/01/02 22:16:29 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	result;
	int				negatif;

	i = 0;
	negatif = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			negatif *= -1;
		str++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - 48);
	if (result > 9223372036854775807 && negatif == 1)
		return (-1);
	else if (result - 1 > 9223372036854775807 && negatif == -1)
		return (0);
	return (result * negatif);
}

static void	ft_message(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\033[32mDONE!\033[0m\n");
	else
		ft_printf("\033[32mQSL!\033[0m\n");
}

void	send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			signal(SIGUSR1, ft_message);
			signal(SIGUSR2, ft_message);
			send_bits(pid, argv[2][i]);
			i++;
		}
		send_bits(pid, '\n');
		send_bits(pid, '\0');
	}
	else
	{
		ft_printf("\033[91mError: Wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client_bonus <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	return (0);
}
