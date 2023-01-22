/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:30:46 by mel-harc          #+#    #+#             */
/*   Updated: 2023/01/21 23:12:36 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif
