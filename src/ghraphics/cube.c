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

#include "../../includes/cube.h"

int	cube(char **map, t_textures *textures,
		t_colors *colors, p_player *player)
{
	t_data	data;

	data.colors = colors;
	data.textures = textures;
	data.layer = player;
	init_game(&data, map);
	mlx_hook(data.game.win, 2, 1L << 0, key_press, &data.game.player);
	mlx_hook(data.game.win, 3, 1L << 1, key_release, &data.game.player);
	mlx_loop_hook(data.game.mlx, draw_loop, &data);
	mlx_loop(data.game.mlx);
	return (0);
}
