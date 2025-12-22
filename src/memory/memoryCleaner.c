/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoryCleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:53:08 by anbaya            #+#    #+#             */
/*   Updated: 2025/11/02 10:55:32 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cube.h"
#include "../../includes/cube.h"

void	free_map(char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	free_cube(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cube->textures[i].img)
			mlx_destroy_image(cube->mlx, cube->textures[i].img);
		i++;
	}
	if (cube->img)
		mlx_destroy_image(cube->mlx, cube->img);
	if (cube->win)
		mlx_destroy_window(cube->mlx, cube->win);
	if (cube->mlx)
	{
		mlx_destroy_display(cube->mlx);
		free(cube->mlx);
	}
}

void	free_config_tow(t_config *config)
{
	if (config->textures)
		free(config->textures);
	if (config->colors)
		free(config->colors);
	if (config->player)
		free(config->player);
	if (config->mlx)
	{
		mlx_destroy_display(config->mlx);
		free(config->mlx);
	}
	free(config);
}

void	free_config(t_config *config)
{
	if (!config)
		return ;
	if (config->file)
		free_map(config->file);
	if (config->map)
		free_map(config->map);
	if (config->nap)
		free_map(config->nap);
	if (config->no_path)
		free(config->no_path);
	if (config->so_path)
		free(config->so_path);
	if (config->we_path)
		free(config->we_path);
	if (config->ea_path)
		free(config->ea_path);
	free_config_tow(config);
}

void	free_data(t_data *data)
{
	free_cube(&data->game);
	if (data->config)
		free_config(data->config);
}
