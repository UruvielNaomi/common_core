NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/ -g

SOURCE := game_code/*.c
GETNEXTLINE := get_next_line/*c
FTPRINTF := ft_printf/*c
LIBRARY := -Lminilibx_mac -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx_mac/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(FTPRINTF) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
	make clean -C $(MINILIBX)
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all


#LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
#MINILIBX := minilibx/