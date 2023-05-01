SRC	=	src/main.c \
		src/raycaster.c \
		src/2d_map.c \
		src/player.c \
		src/move_player.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_raycaster

CFLAGS	=	-Wall -Wextra

CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
