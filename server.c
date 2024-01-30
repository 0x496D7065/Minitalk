/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:41:30 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/30 17:03:57 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_bin(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	count;

	(void)context;
	c |= (signum == SIGUSR2);
	count++;
	if (count == 8)
	{
		count = 0;
		write(1, &c, 1);
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	pid_t	pid;
	int	n;
	struct sigaction sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = print_bin;
	n = sigaction(SIGUSR1, &sa, NULL);
	if (n == -1)
		exit(EXIT_FAILURE);
	n = sigaction(SIGUSR2, &sa, NULL);
	if (n == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
