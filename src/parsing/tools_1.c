/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:08:34 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 15:54:17 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	count_lines(int fd)
{
	int		line_count;
	char	*line;

	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(-1);
	return (line_count);
}

char	**copy_map(char **file, int start, int end)
{
	int		i;
	char	**map;

	map = (char **)malloc((end - start + 2) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		map[i] = ft_strdup(file[start]);
		i++;
		start++;
	}
	map[i] = NULL;
	return (map);
}

int	is_texture(char *line)
{
	if (!line)
		return (0);
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strnstr(line, "NO", 2) || ft_strnstr(line, "SO", 2)
		|| ft_strnstr(line, "WE", 2) || ft_strnstr(line, "EA", 2))
		return (1);
	return (0);
}

int	parse_texture(t_config *config, char *line)
{
	void	*img;

	img = mlx_xpm_file_to_image(config->mlx, line, &(int){40}, &(int){40});
	if (!img)
		return (ft_putstr_fd("Error: Failed to load texture\n", 2), 0);
	return (mlx_destroy_image(config->mlx, img), 1);
}

int	add_texture(char *line, t_config *config, int index)
{
	char	*tmp;
	char	*path;
	int		i;

	i = 2;
	tmp = ft_strtrim(line, " \n\t");
	while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\t'))
		i++;
	path = ft_strdup(tmp + i);
	if (!config->no_path && ft_strnstr(tmp, "NO", 2) && parse_texture(config,
			path))
		return (free(tmp), config->no_path = path, config->no_i = index, 1);
	else if (!config->so_path && ft_strnstr(tmp, "SO", 2)
		&& parse_texture(config, path))
		return (free(tmp), config->so_path = path, config->so_i = index, 1);
	else if (!config->we_path && ft_strnstr(tmp, "WE", 2)
		&& parse_texture(config, path))
		return (free(tmp), config->we_path = path, config->we_i = index, 1);
	else if (!config->ea_path && ft_strnstr(tmp, "EA", 2)
		&& parse_texture(config, path))
		return (free(tmp), config->ea_path = path, config->ea_i = index, 1);
	else
		return (free(tmp), free(path), 0);
}
