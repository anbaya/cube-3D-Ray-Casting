/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 09:24:48 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 17:50:46 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_textures	*bridge_textures(t_config *config)
{
	t_textures	*textures;

	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures->no = config->no_path;
	textures->so = config->so_path;
	textures->we = config->we_path;
	textures->ea = config->ea_path;
	return (textures);
}

t_colors	*bridge_colors(t_config *config)
{
	t_colors	*colors;

	colors = (t_colors *)malloc(sizeof(t_colors));
	if (!colors)
		return (NULL);
	colors->floor[0] = config->f_rgb[0];
	colors->floor[1] = config->f_rgb[1];
	colors->floor[2] = config->f_rgb[2];
	colors->ceiling[0] = config->c_rgb[0];
	colors->ceiling[1] = config->c_rgb[1];
	colors->ceiling[2] = config->c_rgb[2];
	return (colors);
}

p_player	*bridge_player(t_config *config)
{
	p_player	*player;

	player = (p_player *)malloc(sizeof(p_player));
	if (!player)
		return (NULL);
	player->y = config->p_y;
	player->x = config->p_x;
	player->dir = config->p_dir;
	return (player);
}
