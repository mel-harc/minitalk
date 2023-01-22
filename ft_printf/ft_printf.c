/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:33:35 by mel-harc          #+#    #+#             */
/*   Updated: 2023/01/22 22:33:39 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cas(char c, va_list args, int *sum)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), sum);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), sum);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), sum);
	else if (c == 'u')
		ft_putnbr_un(va_arg(args, unsigned int), sum);
	else if (c == '%')
		ft_putchar('%', sum);
	else if (c == 'x')
		ft_puthexa(va_arg(args, unsigned int), sum, 'l');
	else if (c == 'X')
		ft_puthexa(va_arg(args, unsigned int), sum, 'u');
	else if (c == 'p')
	{
		ft_putstr("0x", sum);
		ft_putadd(va_arg(args, unsigned long long), sum);
	}
	else
		ft_putchar(c, sum);
}

int	ft_printf(const char *str, ...)
{
	int		sum;
	int		i;
	va_list	args;

	sum = 0;
	i = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (sum);
			ft_cas(str[i + 1], args, &sum);
			i++;
		}
		else
			ft_putchar(str[i], &sum);
		i++;
	}
	va_end(args);
	return (sum);
}
