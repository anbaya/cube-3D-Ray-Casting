/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:29 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 13:30:30 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

bool is_valid_position(float x, float y, t_cube *game)
{
    int grid_x;
    int grid_y;

    grid_x = (int)(x) / BLOCK_SIZE;
    grid_y = (int)(y) / BLOCK_SIZE;
    if (!(x > BLOCK_SIZE && x < WIDTH - BLOCK_SIZE &&
        y > BLOCK_SIZE && y < HIGHT - BLOCK_SIZE))
        return (false);
    if (game->map[grid_y][grid_x] == '1')
        return (false);
    return (true);
}

float fix_angle(t_player *player)
{
    float angle_speed;

    angle_speed = 0.01;
    if (player->turn_left)
        player->angle -= angle_speed;
    if (player->turn_right)
        player->angle += angle_speed;
    if (player->angle < 0)
        player->angle += 2 * PI;
    if (player->angle > 2 * PI)
        player->angle -= 2 * PI;
    return (player->angle);
}