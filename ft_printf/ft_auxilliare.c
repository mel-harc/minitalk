/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxilliare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:32:30 by mel-harc          #+#    #+#             */
/*   Updated: 2023/01/22 22:32:44 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *sum)
{
	write(1, &c, 1);
	*sum = *sum + 1;
}

void	ft_putstr(char *str, int *sum)
{
	size_t	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], sum);
		i++;
	}
}

void	ft_putnbr(int n, int *sum)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', sum);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, sum);
		ft_putnbr(nb % 10, sum);
	}
	else
		ft_putchar(nb + 48, sum);
}

void	ft_putnbr_un(unsigned int n, int *sum)
{
	if (n <= 9)
		ft_putchar(n + 48, sum);
	else if (n > 9)
	{
		ft_putnbr_un(n / 10, sum);
		ft_putnbr_un(n % 10, sum);
	}
}
