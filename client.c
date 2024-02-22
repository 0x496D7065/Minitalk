/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:56:37 by lpetit            #+#    #+#             */
/*   Updated: 2024/02/09 14:19:57 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	g_signal_processed;

static void	send_sig(int pid, char *tosend)
{
	int	i;

	i = 0;
	while (tosend[i])
	{
		if (tosend[i] == '0')
			kill(pid, SIGUSR1);
		else if (tosend[i] == '1')
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		g_signal_processed = 0;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	char				*tosend;
	int					i;

	if (argc == 3)
	{
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_RESTART | SA_SIGINFO;
		sa.sa_sigaction = sig_handler;
		i = sigaction(SIGUSR1, &sa, NULL);
		if (i == -1)
			exit(EXIT_FAILURE);
		g_signal_processed = 0;
		while (argv[2][i])
		{
			if (g_signal_processed == 0)
			{
				g_signal_processed = 1;
				tosend = char_to_bin(argv[2][i++]);
				send_sig(ft_atoi(argv[1]), tosend);
				free(tosend);
			}
		}
	}
	return (0);
}
