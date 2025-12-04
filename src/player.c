/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:26 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 14:38:06 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HIGHT / 2;
	player->key_down = false;
	player->key_up = false;
	player->key_left = false;
	player->key_right = false;
	player->turn_left = false;
	player->turn_right = false;
	player->angle = PI / 2;
}
