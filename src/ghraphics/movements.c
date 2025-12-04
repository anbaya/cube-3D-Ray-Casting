/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:23 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 17:43:39 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	key_up(t_player *player, t_cube *game)
{
	int		speed;
	float	new_x;
	float	new_y;

	speed = 2;
	new_x = player->x + cos(player->angle) * speed;
	new_y = player->y + sin(player->angle) * speed;
	if (is_valid_position(new_x, new_y, game))
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	key_down(t_player *player, t_cube *game)
{
	int		speed;
	float	new_x;
	float	new_y;

	speed = 2;
	new_x = player->x - cos(player->angle) * speed;
	new_y = player->y - sin(player->angle) * speed;
	if (is_valid_position(new_x, new_y, game))
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	key_left(t_player *player, t_cube *game)
{
	int		speed;
	float	new_x;
	float	new_y;

	speed = 2;
	new_x = player->x + sin(player->angle) * speed;
	new_y = player->y - cos(player->angle) * speed;
	if (is_valid_position(new_x, new_y, game))
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	key_right(t_player *player, t_cube *game)
{
	int		speed;
	float	new_x;
	float	new_y;

	speed = 2;
	new_x = player->x - sin(player->angle) * speed;
	new_y = player->y + cos(player->angle) * speed;
	if (is_valid_position(new_x, new_y, game))
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	move_player(t_player *player, t_cube *game, t_data *data)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	fix_angle(player, data->layer);
	if (player->key_up)
		key_up(player, game);
	if (player->key_down)
		key_down(player, game);
	if (player->key_left)
		key_left(player, game);
	if (player->key_right)
		key_right(player, game);
}
