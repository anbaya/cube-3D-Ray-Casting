/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:18 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 15:24:32 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	close_window(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == W)
		data->game.player.key_up = true;
	if (keycode == S)
		data->game.player.key_down = true;
	if (keycode == A)
		data->game.player.key_left = true;
	if (keycode == D)
		data->game.player.key_right = true;
	if (keycode == LEFT)
		data->game.player.turn_left = true;
	if (keycode == RIGHT)
		data->game.player.turn_right = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->game.player.key_up = false;
	if (keycode == S)
		data->game.player.key_down = false;
	if (keycode == A)
		data->game.player.key_left = false;
	if (keycode == D)
		data->game.player.key_right = false;
	if (keycode == LEFT)
		data->game.player.turn_left = false;
	if (keycode == RIGHT)
		data->game.player.turn_right = false;
	if (keycode == ESC)
		close_window(data);
	return (0);
}
