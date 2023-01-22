# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-harc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 22:31:50 by mel-harc          #+#    #+#              #
#    Updated: 2023/01/22 22:32:10 by mel-harc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_auxilliare.c ft_hexa.c ft_printf.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

%.o : %.c	ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re
