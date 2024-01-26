/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:41:30 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/26 11:29:50 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_bin(int signum)
{
	static char	c;
	static int	count;

	if (signum == SIGUSR1)
		c <<= 1;
	if (signum == SIGUSR2)
		c = (c << 1) | 1;
	count++;
	if (count == 8)
	{
		ft_printf("%c", c);
		c = 0;
		count = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, print_bin);
	signal(SIGUSR2, print_bin);
	while (1)
		pause();
	return (0);
}
