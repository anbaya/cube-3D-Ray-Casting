#include "../includes/cube.h"

void init_player(t_player *player)
{
    player->x = WIDTH / 2;
    player->y = HIGHT / 2;
    player->key_down = false;
    player->key_up = false;
    player->key_left = false;
    player->key_right = false;
    player->turn_left = false;
    player->turn_right = false;
    player->angle = PI / 2; // Facing upwards initially
}

int key_press(int keycode, t_player *player)
{
    if (keycode == W)
        player->key_up = true;
    if (keycode == S)
        player->key_down = true;
    if (keycode == A)
        player->key_left = true;
    if (keycode == D)
        player->key_right = true;

    if (keycode == LEFT) // Left arrow key
        player->turn_left = true;

    if (keycode == RIGHT) // Right arrow key
        player->turn_right = true;
    return 0;
}

int key_release(int keycode, t_player *player)
{
    if (keycode == W)
        player->key_up = false;
    if (keycode == S)
        player->key_down = false;
    if (keycode == A)
        player->key_left = false;
    if (keycode == D)
        player->key_right = false;
    if (keycode == LEFT)
        player->turn_left = false;
    if (keycode == RIGHT)
        player->turn_right = false;
    if (keycode == ESC)
        exit(0);
    return 0;
}

void move_player(t_player *player, t_cube *game)
{
    int speed = 1;
    float angle_speed = 0.01;
    float cos_angle = cos(player->angle);
    float sin_angle = sin(player->angle);

    if (player->turn_left)
        player->angle -= angle_speed;
    if (player->turn_right)
        player->angle += angle_speed;
    if (player->angle > 2 * PI)
        player->angle = 0;
    if (player->angle < 0)
        player->angle = 2 * PI;

    if (player->key_up)
    {
        if (player->x + cos_angle * speed > BLOCK_SIZE && player->x + cos_angle * speed < WIDTH - BLOCK_SIZE &&
            player->y + sin_angle * speed > BLOCK_SIZE && player->y + sin_angle * speed < HIGHT - BLOCK_SIZE &&
           game->map[(int)(player->y + sin_angle * speed) / BLOCK_SIZE][(int)(player->x + cos_angle * speed) / BLOCK_SIZE] != '1')
        {
            player->x += cos_angle * speed;
            player->y += sin_angle * speed;
        }
    }
    if (player->key_down)
    {
        if (player->x - cos_angle * speed > BLOCK_SIZE && player->x - cos_angle * speed < WIDTH - BLOCK_SIZE &&
            player->y - sin_angle * speed > BLOCK_SIZE && player->y - sin_angle * speed < HIGHT - BLOCK_SIZE &&
           game->map[(int)(player->y - sin_angle * speed) / BLOCK_SIZE][(int)(player->x - cos_angle * speed) / BLOCK_SIZE] != '1')
        {
            player->x -= cos_angle * speed;
            player->y -= sin_angle * speed;
        }
    }
    if (player->key_left)
    {
        if (player->x + sin_angle * speed > BLOCK_SIZE && player->x + sin_angle * speed < WIDTH - BLOCK_SIZE &&
            player->y - cos_angle * speed > BLOCK_SIZE && player->y - cos_angle * speed < HIGHT - BLOCK_SIZE &&
           game->map[(int)(player->y - cos_angle * speed) / BLOCK_SIZE][(int)(player->x + sin_angle * speed) / BLOCK_SIZE] != '1')
        {
            player->x += sin_angle * speed;
            player->y -= cos_angle * speed;
        }
    }
    if (player->key_right)
    {
        if (player->x - sin_angle * speed > BLOCK_SIZE && player->x - sin_angle * speed < WIDTH - BLOCK_SIZE &&
            player->y + cos_angle * speed > BLOCK_SIZE && player->y + cos_angle * speed < HIGHT - BLOCK_SIZE &&
           game->map[(int)(player->y + cos_angle * speed) / BLOCK_SIZE][(int)(player->x - sin_angle * speed) / BLOCK_SIZE] != '1')
        {
            player->x -= sin_angle * speed;
            player->y += cos_angle * speed;
        }
    }
}