# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 13:26:35 by nstacia           #+#    #+#              #
#    Updated: 2024/04/03 13:32:11 by nstacia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	check.c \
			free.c \
			index.c \
			init.c \
			insertion.c \
			main.c \
			organise_b.c \
			push_swap.c \
			push.c \
			rotate.c \
			stack_b_rotate.c \
			swap.c \

OBJECTS = ${SOURCES:.c=.o}

NAME = push_swap
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/ft_printf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(PRINTF):
	$(MAKE) -C ./ft_printf

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(PRINTF)

clean:
	${RM} ${OBJECTS}

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
