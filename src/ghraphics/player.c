/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:26 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 17:45:42 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	init_player(t_player *player, t_data *data)
{
	if (!data->layer)
	{
		player->x = WIDTH / 2;
		player->y = HIGHT / 2;
	}
	else
	{
		player->x = data->layer->x * data->game.block_size;
		player->y = data->layer->y * data->game.block_size;
	}
	player->key_down = false;
	player->key_up = false;
	player->key_left = false;
	player->key_right = false;
	player->turn_left = false;
	player->turn_right = false;
	if (data->layer->dir == 'N')
		player->angle = 3 * PI / 2;
	else if (data->layer->dir == 'S')
		player->angle = PI / 2;
	else if (data->layer->dir == 'E')
		player->angle = 0;
	else if (data->layer->dir == 'W')
		player->angle = PI;
	else
		player->angle = 0;
}
