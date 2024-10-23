/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:54:54 by mel-harc          #+#    #+#             */
/*   Updated: 2023/01/22 02:26:06 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_message(char data, int pid, int x)
{
	int	count;

	count = -1;
	while (++count < 8)
	{
		if (data & (0x80 >> count))
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep(x);
	}
}

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 3)
		return (1);
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
			return (1);
	}
	return (0);
}

size_t	ft_counter(char *av)
{
	int	x;

	x = ft_strlen(av);
	if (x >= 10000)
		return (1300);
	else
		return (100);
}

void	finaly_function(int n)
{
	if (n == SIGUSR1)
		ft_printf("RECEIVE 👍\n");
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;
	int	x;

	i = -1;
	signal(SIGUSR1, finaly_function);
	if (ft_check_args(ac, av))
		return (-1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (0);
	x = ft_counter(av[2]);
	while (av[2][++i])
		handle_message(av[2][i], pid, x);
	handle_message('\0', pid, x);
	return (0);
}
