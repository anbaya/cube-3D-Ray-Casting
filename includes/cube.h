#pragma once

# define WIDTH 960
# define HIGHT 640
# define BLOCK_SIZE 64
# define CELLING_COLOR 0x87CEEB
# define FLOOR_COLOR 0x228B22

# define A 97
# define S 115
# define D 100
# define W 119
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363

# define PI 3.1415926535


#include "minilibx-linux/mlx.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"

typedef struct player
{
    float x;
    float y;
    bool key_up;
    bool key_down;
    bool key_left;
    bool key_right;
    bool turn_left;
    bool turn_right;
    float angle;
} t_player;

typedef struct cube
{
    void *mlx;
    void *win;
    void *img;
    t_player player;
    char **map;
    char *img_start;
    int bpp;
    int size_line;
    int endian;
}  t_cube;


void init_player(t_player *player);
int key_press(int keycode, t_player *player);
int key_release(int keycode, t_player *player);
void move_player(t_player *player, t_cube *game);
int init_game(t_cube *game);
int draw_loop(t_cube *game);
void put_pixel(int x, int y, int color, t_cube *game);
