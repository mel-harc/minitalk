/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:38:42 by mel-harc          #+#    #+#             */
/*   Updated: 2023/01/21 23:16:00 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signl_handler(int signum, siginfo_t *info, void *context)
{
	static int	bits;
	static char	c;
	static int	client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		c = 0xff;
		bits = 0;
	}
	client_pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		c = 0xff;
		bits = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;
	pid_t				pid;

	(void)ac;
	(void)av;
	action.sa_sigaction = &signl_handler;
	pid = getpid();
	ft_printf("💳 THIS IS PID : %d\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
