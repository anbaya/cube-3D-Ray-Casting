/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:29 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 17:44:20 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

bool	is_valid_position(float x, float y, t_cube *game)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(x) / game->block_size;
	grid_y = (int)(y) / game->block_size;
	if (game->map[grid_y][grid_x] == '1')
		return (false);
	return (true);
}

float	fix_angle(t_player *player, p_player *layer)
{
	float	angle_speed;

	angle_speed = 0.03;
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
