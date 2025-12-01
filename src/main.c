#include "../includes/cube.h"

void put_pixel(int x, int y, int color, t_cube *game)
{
    if (x < 0 || y < 0 || x >= WIDTH || y >= HIGHT)
        return;
    int index = (y * game->size_line) + (x * (game->bpp / 8));

    game->img_start[index] = color & 0xFF;
    game->img_start[index + 1] = (color >> 8) & 0xFF;
    game->img_start[index + 2] = (color >> 16) & 0xFF;
    game->img_start[index + 3] = (color >> 24) & 0xFF;
}

char **get_map(void)
{
    char **map = malloc(sizeof(char *) * 11);
    map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100000000000001";
    map[3] = "100000100000001";
    map[4] = "100000000000001";
    map[5] = "100000000000001";
    map[6] = "100001000000001";
    map[7] = "100000001100001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
    return (map);
}

void draw_square(int x, int y, int size, int color, t_cube *game)
{
    for (int i = 0; i < size; i++)
        put_pixel(x + i, y, color, game);
    for (int i = 0; i < size; i++)
        put_pixel(x, y + i, color, game);
    for (int i = 0; i < size; i++)
        put_pixel(x + size, y + i, color, game);
    for (int i = 0; i < size; i++)
        put_pixel(x + i, y + size, color, game);
}

void draw_map(t_cube *game)
{
    char **map = game->map;
    int color = 0x0000FF;
    for(int y = 0; map[y]; y++)
        for(int x = 0; map[y][x]; x++)
            if(map[y][x] == '1')
                draw_square(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, color, game);
}

int init_game(t_cube *game)
{
    init_player(&game->player);
    game->map = get_map();
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HIGHT, "cube");
    game->img = mlx_new_image(game->mlx, WIDTH, HIGHT);
    game->img_start = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return 0;
}

bool touch(float px, float py, t_cube *game)
{
    int x = px / BLOCK_SIZE;
    int y = py / BLOCK_SIZE;
    if (game->map[y][x] == '1')
        return true;
    return false;
}

float distance(float dx, float dy)
{
    return sqrt(dx * dx + dy * dy);
}

float fixed_dist(float x1, float y1, float x2, float y2, t_cube *game)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;
    float angle = atan2(delta_y, delta_x) - game->player.angle;
    float fix_dist = distance(delta_x, delta_y) * cos(angle);
    return fix_dist;
}


void draw_line(t_player *player, t_cube *game, float start_x, int i)
{
    float cos_angle = cos(start_x);
    float sin_angle = sin(start_x);
    float ray_x = player->x;
    float ray_y = player->y;
    while (!touch(ray_x, ray_y, game))
    {
        // put_pixel(ray_x, ray_y, 0xFF0000, game);
        ray_x += cos_angle;
        ray_y += sin_angle;
    }
    float dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
    float height = (BLOCK_SIZE / dist) * (WIDTH / 2);
    int start_y = (HIGHT - height) / 2;
    int end = start_y + height;
    while(start_y < end)
    {
        put_pixel(i, start_y, 255, game);
        start_y++;
    }
    
}

void draw_floor_and_ceiling(t_cube *game)
{
    for (int y = 0; y < HIGHT / 2; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            put_pixel(x, y, CELLING_COLOR, game);
        }
    }
    for (int y = HIGHT / 2; y < HIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            put_pixel(x, y, FLOOR_COLOR, game);
        }
    }
}


int draw_loop(t_cube *game)
{
    t_player *player = &game->player;
    mlx_destroy_image(game->mlx, game->img);
    game->img = mlx_new_image(game->mlx, WIDTH, HIGHT);
    game->img_start = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    move_player(player, game);
    float fraction = PI / 3 / WIDTH;
    float start_x = player->angle - (PI / 6);
    int i = 0;
    draw_floor_and_ceiling(game);
    while (i < WIDTH)
    {
        draw_line(player, game, start_x, i);
        start_x += fraction;
        i++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return 0;
}

int main()
{
    t_cube game;

    init_game(&game);

    mlx_hook(game.win, 2, 1L<<0, key_press, &game.player);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);

    mlx_loop_hook(game.mlx, draw_loop, &game);
    mlx_loop(game.mlx);

    return 0;
}