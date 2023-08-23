SRC	=	src/player/create.c \
		src/player/move.c \
		src/player/controls_move.c \
		src/map/2d_map.c \
		src/map/3d_map.c \
		src/math/math_tools.c \
		src/math/angle.c \
		src/options/mouse_view.c \
		src/options/pause.c \
		src/options/resolution.c \
		src/rays/cast_rays.c \
		src/main.c \
		src/raycaster.c \
		src/update.c

OBJ	=	$(SRC:.c=.o)

NAME	=	raycaster

CFLAGS	=	-Wall -Wextra

# add this in CSFML_FLAGS for mac "-L/opt/homebrew/Cellar/csfml/2.5.2_1/lib"

CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML_FLAGS) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
