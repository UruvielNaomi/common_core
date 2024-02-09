NAME := so_long #name of the executable

CC := gcc #compiler used

CFLAGS := -Wall -Wextra -Werror -Iheaders/ #compiler flags -Iheaders tells the compliker to look in the headers/ directory for header files.

SOURCE := gameplay_code/*.c #look in the gameplay_code/ directory for .c files
# GETNEXTLINE := get_next_line/*c  Dont yet understand why we would need a get next line, so commented out for now.
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
# -framework OpenGL -framework AppKit: These flags are specific to macOS and are used to link the OpenGL and AppKit frameworks. 
# OpenGL (Open Graphics Library) is a cross-language, cross-platform application programming interface (API) for rendering 2D and 3D vector graphics. 
# AppKit is a framework containing all the objects you need to implement your graphical, event-driven user interface: windows, panels, buttons, menus, scrollers, and text fields.

MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all