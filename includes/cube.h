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

#define no_texture "./textures/no_wall.xpm"
#define so_texture "./textures/so_wall.xpm"
#define ea_texture "./textures/ea_wall.xpm"
#define we_texture "./textures/we_wall.xpm"

#include "minilibx-linux/mlx.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"

typedef enum e_wall_side
{
    NORTH,
    SOUTH,
    EAST,
    WEST
} t_wall_side;

typedef struct s_texture
{
    void *img;
    char *data;
    int width;
    int height;
    int bpp;
    int size_line;
    int endian;
} t_texture;

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
    t_texture textures[4];
}  t_cube;


void init_player(t_player *player);
int key_press(int keycode, t_player *player);
int key_release(int keycode, t_player *player);
void move_player(t_player *player, t_cube *game);
int init_game(t_cube *game);
int draw_loop(t_cube *game);
void put_pixel(int x, int y, int color, t_cube *game);
char **get_map();
void draw_line(t_player *player, t_cube *game, float ray_angle, int i);
float fixed_dist(float x1, float y1, float x2, float y2, t_cube *game);
bool touch(float px, float py, t_cube *game, t_wall_side *wall_side, float prev_x, float prev_y);