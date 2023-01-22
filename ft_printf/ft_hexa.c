/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:33:04 by mel-harc          #+#    #+#             */
/*   Updated: 2023/01/22 22:33:15 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int n, int *sum, char c)
{
	if (n > 9 && n < 16)
	{
		if (c == 'u')
			ft_putchar("abcdef"[n % 10] - 32, sum);
		if (c == 'l')
			ft_putchar("abcdef"[n % 10], sum);
	}
	else if (n > 15)
		ft_nbrhexa(n, sum, c);
	else
		ft_putchar(n + 48, sum);
}

void	ft_nbrhexa(unsigned int n, int *sum, char c)
{
	if (n > 15)
	{
		ft_nbrhexa(n / 16, sum, c);
		ft_puthexa(n % 16, sum, c);
	}
	else
		ft_puthexa(n, sum, c);
}

void	ft_putadd(unsigned long long nb, int *sum)
{
	if (nb > 9 && nb < 16)
		ft_putchar("abcdef"[nb % 10], sum);
	else if (nb > 15)
	{
		ft_putadd(nb / 16, sum);
		ft_putadd(nb % 16, sum);
	}
	else
		ft_putchar(nb + 48, sum);
}
