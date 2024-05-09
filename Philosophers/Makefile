# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 10:08:30 by Naomi             #+#    #+#              #
#    Updated: 2024/05/09 10:41:52 by Naomi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	free.c \
			init.c \
			main.c \
			status.c \

OBJECTS = ${SOURCES:.c=.o}

NAME = Philosophers
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
