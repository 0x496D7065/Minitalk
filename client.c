/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:56:37 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/29 19:29:41 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_sig(pid_t pid, char *tosend)
{
	int	i;

	i = 0;
	while (tosend[i])
	{
		//ft_printf("%c", tosend[i]);
		if (tosend[i] == '0')
		{
			kill(pid, SIGUSR1);
			//ft_printf("=%s ", "SIG1");
		}
		else if (tosend[i] == '1')
		{
			kill(pid, SIGUSR2);
			//ft_printf("=%s ", "SIG2");
		}
		i++;
		usleep(100);
	}
}

int	sig_handler(int signum, siginfo_t *info, void *context)
{
	if (signum == SIGUSR1)
		return (1);
}

int	main(int argc, char **argv)
{
	struct	sigaction sa;
	pid_t	pid;
	char	*tosend;
	int		i;

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
		while (argv[2][i])
		{
			tosend = char_to_bin(argv[2][i]);
			//ft_printf("%d\n", pid);
			//ft_printf("%c\n", argv[2][i]);
			//ft_printf("%s\n", tosend);
			send_sig(pid, tosend);
			i++;
			usleep(10);
		}
		tosend = char_to_bin('\0');
		send_sig(pid, tosend);
		free(tosend);
	}
	return (0);
}
