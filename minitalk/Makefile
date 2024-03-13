SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

PRINTF = ft_printf

all:
	

clean:

fclean: clean
	make clean -C $(MINILIBX)
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all
