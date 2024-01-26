/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:56:37 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/26 11:46:59 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_sig(pid_t pid, char *tosend)
{
	int	i;

	i = 0;
	while (tosend[i] != '\0')
	{
		ft_printf("%c", tosend[i]);
		if (tosend[i] == '0')
		{
			kill(pid, SIGUSR1);
			ft_printf("=%s ", "SIG1");
		}
		if (tosend[i] == '1')
		{
			kill(pid, SIGUSR2);
			ft_printf("=%s ", "SIG2");
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*tosend;
	int		i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			tosend = char_to_bin(argv[2][i]);
			ft_printf("%d\n", pid);
			ft_printf("%c\n", argv[2][i]);
			ft_printf("%s\n", tosend);
			send_sig(pid, tosend);
			i++;
		}
		tosend = char_to_bin('\0');
		send_sig(pid, tosend);
		free(tosend);
	}
	return (0);
}
