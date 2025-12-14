/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:08:39 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 16:50:04 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_config	*init_config(char *filename)
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config));
	if (!config)
		return (NULL);
	*config = (t_config){0};
	config->mlx = mlx_init();
	config->file = read_file(filename);
	if (!config->file)
		return (free(config), NULL);
	if (!file_loader(config->file, config))
		return (free(config->file), free(config), NULL);
	return (config);
}

int	main(int argc, char **argv)
{
	t_config	*config;
	t_textures	*textures;
	t_colors	*colors;
	t_layer		*player;

	if (argc != 2)
		return (ft_putstr_fd("Error\nInvalid number of arguments\n", 2), 1);
	if (!fname_check(argv[1]))
		return (ft_putstr_fd("Error\nInvalid file\n", 2), 1);
	config = init_config(argv[1]);
	if (!config)
		return (free_config(config), ft_putstr_fd("Error\nInvalid File\n", 2), 1);
	if (!get_player(config, config->map))
		return (free_config(config), ft_putstr_fd("Error\nNo player found or invalid player position\n", 2), 1);
	if (map_parsing(config, config->p_x, config->p_y))
		return (free_config(config), ft_putstr_fd("Error\nInvalid map\n", 2), 1);
	if (map_char_check(config->map))
		return (free_config(config), ft_putstr_fd("Error\nInvalid map characters\n", 2), 1);
	config->textures = bridge_textures(config);
	config->colors = bridge_colors(config);
	config->player = bridge_player(config);
	return (cube(config));
}
