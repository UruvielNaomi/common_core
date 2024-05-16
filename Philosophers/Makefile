# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 10:08:30 by Naomi             #+#    #+#              #
#    Updated: 2024/05/16 15:37:30 by Naomi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	calculate_time.c\
			free.c \
			init.c \
			main.c \
			status.c \
			threads.c\
			time_stamps.c\

OBJECTS = ${SOURCES:.c=.o}

NAME = Philosophers
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)


$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	${RM} ${OBJECTS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
