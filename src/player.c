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
    {
        player->key_up = true;
        printf("Key W pressed\n");
    }
    if (keycode == S)
    {
        player->key_down = true;
        printf("Key S pressed\n");
    }
    if (keycode == A)
    {
        player->key_left = true;
        printf("Key A pressed\n");
    }
    if (keycode == D)
    {
        player->key_right = true;
        printf("Key D pressed\n");
    }
    if (keycode == LEFT) // Left arrow key
    {
        player->turn_left = true;
        printf("Left arrow key pressed\n");
    }
    if (keycode == RIGHT) // Right arrow key
    {
        player->turn_right = true;
        printf("Right arrow key pressed\n");
    }
    if (keycode == ESC) // Escape key
    {
        printf("Escape key pressed, exiting...\n");
    }
    return 0;
}

int key_release(int keycode, t_player *player)
{
    if (keycode == W)
    {
        player->key_up = false;
        printf("Key W released\n");
    }
    if (keycode == S)
    {
        player->key_down = false;
        printf("Key S released\n");
    }
    if (keycode == A)
    {
        player->key_left = false;
        printf("Key A released\n");
    }
    if (keycode == D)
    {
        player->key_right = false;
        printf("Key D released\n");
    }
    if (keycode == LEFT) // Left arrow key
    {
        player->turn_left = false;
        printf("Left arrow key released\n");
    }
    if (keycode == RIGHT) // Right arrow key
    {
        player->turn_right = false;
        printf("Right arrow key released\n");
    }
    if (keycode == ESC) // Escape key
    {
        printf("Escape key released, exiting...\n");
        exit(0);
    }
    return 0;
}

void move_player(t_player *player)
{
    int speed = 1;
    float angle_speed = 0.03;
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
        player->x += cos_angle * speed;
        player->y += sin_angle * speed;
    }
    if (player->key_down)
    {
        player->x -= cos_angle * speed;
        player->y -= sin_angle * speed;
    }
    if (player->key_left)
    {
        player->x += sin_angle * speed;
        player->y -= cos_angle * speed;
    }
    if (player->key_right)
    {
        player->x -= sin_angle * speed;
        player->y += cos_angle * speed;
    }
}