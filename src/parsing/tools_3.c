/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:09:26 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 17:50:18 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_player(t_config *config, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				config->p_x = j;
				config->p_y = i;
				if (player_position_check(j, i, config))
					return (0);
				config->p_dir = map[i][j];
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	index_check(t_config *config, int i)
{
	if (i != config->no_i && i != config->so_i && i != config->we_i
		&& i != config->ea_i && i != config->f_i && i != config->c_i)
		return (1);
	return (0);
}

int	before_map(t_config *config, char **file, int i)
{
	int	j;

	j = 0;
	while (file[i] && i < config->map_start)
	{
		j = 0;
		if (index_check(config, i))
		{
			while (file[i][j] == ' ' || file[i][j] == '\t')
				j++;
			if (file[i][j] != '\0' && file[i][j] != '\n')
				return (0);
		}
		i++;
	}
	return (1);
}

int	after_map(char **file, int i)
{
	int	j;

	while (file[i])
	{
		j = 0;
		while (file[i] && (file[i][j] == ' ' || file[i][j] == '\t'))
			j++;
		if (file[i] && (file[i][j] != '\0' && file[i][j] != '\n'))
			return (0);
		i++;
	}
	return (1);
}

int	parse_file(char **file, t_config *config)
{
	int	i;

	i = 0;
	if (!before_map(config, file, i))
		return (0);
	i = config->map_end + 1;
	if (!after_map(file, i))
		return (0);
	return (1);
}
