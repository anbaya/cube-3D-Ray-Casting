NAME = Cube3D
cc = cc
OBJ = $(SRC:.c=.o)

LFLAGS = -L./includes/minilibx-linux -lmlx -lXext -lX11 -lm -lz
INCLUDES = includes/minilibx-linux/libmlx.a
SRC = src/main.c src/player.c

all: $(NAME)

$(NAME): $(OBJ)
	$(cc) -g $(SRC) -o $(NAME) $(INCLUDES) $(LFLAGS)
clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(OBJ)
	rm $(NAME)