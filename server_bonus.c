/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:48:23 by mfadil            #+#    #+#             */
/*   Updated: 2023/01/01 17:21:56 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;
	static int	pid;

	(void)info;
	(void)s;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i = 0;
		bit = 0;
	}
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		if (i == '\0')
			kill(info->si_pid, SIGUSR1);
		else
			kill(info->si_pid, SIGUSR2);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;
	int					pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mError: Wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./server_bonus.\033[0m \n");
		return (0);
	}
	pid = getpid();
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	signal.sa_sigaction = handler;
	sigemptyset(&signal.sa_mask);
	while (argc == 1)
	{
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		pause();
	}
	return (0);
}
