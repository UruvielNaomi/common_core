# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Naomi <Naomi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 10:46:03 by nstacia           #+#    #+#              #
#    Updated: 2024/03/21 13:28:36 by Naomi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/ft_printf.a
NAME = minitalk.a
RM = rm -rf
LIBC = ar rcs

SERVER = server
CLIENT = client

SV_SRCS = server.c
SV_OBJS = $(SV_SRCS:.c=.o)

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)
	$(LIBC) $(NAME) $(SV_OBJS) $(CLIENT_OBJS)

$(LIBFT):
	$(MAKE) -C ./libft
$(PRINTF):
	$(MAKE) -C ./ft_printf
$(SERVER): $(SV_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SV_OBJS) $(LIBFT) $(PRINTF) -o server
$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) $(PRINTF) -o client

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
	$(RM) $(SV_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./ft_printf
	$(RM) $(SERVER) $(CLIENT) $(NAME)

re: fclean all

.PHONY : all clean fclean re