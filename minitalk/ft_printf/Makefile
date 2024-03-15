# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 16:32:56 by nstacia           #+#    #+#              #
#    Updated: 2024/03/15 15:54:12 by Naomi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c \
		ft_putchar.c \
		ft_puthex.c \
		ft_puthex_uintptr.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putunsigned.c \
		ft_toupper.c \
				
OBJS = ${SRCS:.c=.o}
NAME = ft_printf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re