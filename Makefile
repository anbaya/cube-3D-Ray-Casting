NAME = cub3D
CC = cc
OBJ = $(SRC:.c=.o)
LIBFT = includes/libft/libft.a

LFLAGS = -Wall -Werror -Wextra -L./includes/mlx -lmlx -lXext -lX11 -lm -lz
INCLUDES = includes/mlx/libmlx.a
SRC = src/cube.c src/ghraphics/player.c src/ghraphics/movements.c src/ghraphics/key_hooks.c src/ghraphics/positions.c \
		src/ghraphics/initialize.c src/ghraphics/rendering.c src/ghraphics/raycasting.c src/parsing/main.c src/parsing/bridge.c \
		src/parsing/first_parsing.c src/parsing/get_next_line.c src/parsing/reading.c src/parsing/tools_1.c \
		src/parsing/tools_2.c src/parsing/tools_3.c src/parsing/tools_4.c src/parsing/tools_5.c src/parsing/tools_6.c src/memory/memoryCleaner.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -g $(SRC) -o $(NAME) $(LIBFT) $(INCLUDES) $(LFLAGS)
clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(OBJ)
	rm $(NAME)
re: fclean all
.PHONY: all clean fclean re