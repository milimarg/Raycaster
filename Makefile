SRC	=	src/main.c \
		src/player/create.c \
		src/player/move.c \
		src/2d_map.c \
		src/raycaster.c \
		src/cast_rays.c \
		src/math_tools.c \
		src/3d_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_raycaster

CFLAGS	=	-Wall -Wextra

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
