/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:29 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 14:51:59 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

bool	is_valid_position(float x, float y, t_cube *game)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(x) / game->block_size;
	grid_y = (int)(y) / game->block_size;
	if (!(x > game->block_size && x < WIDTH - game->block_size
			&& y > game->block_size && y < HIGHT - game->block_size))
		return (false);
	if (game->map[grid_y][grid_x] == '1')
		return (false);
	return (true);
}

float	fix_angle(t_player *player)
{
	float	angle_speed;

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
