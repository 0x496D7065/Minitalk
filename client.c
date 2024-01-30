/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:56:37 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/30 16:50:13 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int signal_processed;

static void	send_sig(int pid, char *tosend)
{
	int	i;
	
	i = 0;
	while (tosend[i])
	{
		signal_processed = 1;
		ft_printf("%c", tosend[i]);
		if (tosend[i] == '0')
		{
			kill(pid, SIGUSR1);
			ft_printf("=%s ", "SIG1");
		}
		else if (tosend[i] == '1')
		{
			kill(pid, SIGUSR2);
			ft_printf("=%s ", "SIG2");
		}
		i++;
		while (signal_processed != 0)
		{
			ft_printf("%d\n", signal_processed);
		}
	}
}
void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		signal_processed = 0;
		ft_printf("%ss\n", "signal reset");
	}
}
int	main(int argc, char **argv)
{
	struct	sigaction sa;
	pid_t	pid;
	char	*tosend;
	int		i;
	int		n;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_RESTART | SA_SIGINFO;
		sa.sa_handler = &sig_handler;
		n = sigaction(SIGUSR1, &sa, NULL);
		if (n == -1)
			exit(EXIT_FAILURE);
		signal_processed = 0;
		//signal(SIGUSR1, &sig_handler);
		send_sig(pid, argv[2]);
		while (argv[2][i])
		{
			tosend = char_to_bin(argv[2][i]);
			//ft_printf("%d\n", pid);
			//ft_printf("%c\n", argv[2][i]);
			//ft_printf("%s\n", tosend);
			send_sig(pid, tosend);
			free(tosend);
			i++;
		}
		tosend = char_to_bin('\0');
		send_sig(pid, tosend);
		free(tosend);
	}
	return (0);
}
