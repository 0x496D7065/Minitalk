/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:41:30 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/29 19:29:44 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_bin(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	count;

	if (signum == SIGUSR1)
	{
		c <<= 1;
		//ft_printf("%s\n", "SIG1");
	}
	else if (signum == SIGUSR2)
	{
		c = (c << 1) | 1;
		//ft_printf("%s\n", "SIG2");
	}
	count++;
	//ft_printf("%d\n", count);
	if (count == 8)
	{
		count = 0;
		//if (c == '\0')
			//kill(info.si_pid, SIGUSR1);
		ft_printf("%c", c);
		c = NULL;
	}
	kill(info.si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t	pid;
	int	n;
	struct sigaction sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_handler = &print_bin;
	n = sigaction(SIGUSR1, &sa, NULL);
	if (n == -1)
		exit(EXIT_FAILURE);
	n = sigaction(SIGUSR2, &sa, NULL);
	if (n == -1)
		exit(EXIT_FAILURE);
	//signal(SIGUSR1, print_bin);
	//signal(SIGUSR2, print_bin);
	while (1)
		pause();
	return (0);
}
