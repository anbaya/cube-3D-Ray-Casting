/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:20 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 17:42:45 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	cube(t_config *config)
{
	t_data	data;

	data.colors = config->colors;
	data.textures = config->textures;
	data.layer = config->player;
	data.config = config;
	init_game(&data, config);
	mlx_hook(data.game.win, 17, 0, close_window, &data);
	mlx_hook(data.game.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.game.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.game.mlx, draw_loop, &data);
	mlx_loop(data.game.mlx);
	return (0);
}
