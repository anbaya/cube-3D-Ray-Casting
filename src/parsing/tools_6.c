/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoir <anoir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:50:46 by anoir             #+#    #+#             */
/*   Updated: 2025/12/24 11:33:12 by anoir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_in_borther(int x, int y, char **map)
{
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x - 1] == ' '
		|| map[y][x + 1] == ' ')
		return (1);
	if (map[y - 1][x] == '\0' || map[y + 1][x] == '\0' || map[y][x - 1] == '\0'
		|| map[y][x + 1] == '\0')
		return (1);
	if (map[y - 1][x] == '\n' || map[y + 1][x] == '\n' || map[y][x - 1] == '\n'
		|| map[y][x + 1] == '\n')
		return (1);
	return (0);
}

int	player_position_check(int x, int y, t_config *config)
{
	if (x <= 0 || y <= 0 || is_in_borther(x, y, config->map))
		return (1);
	return (0);
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || is_player_char(c));
}

int	holes_in_map(char **map, t_config *config)
{
	int	x;
	int	y;

	y = 0;
	while (y < config->num_rows)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' && (!is_valid_char(map[y][x + 1])
			|| !is_valid_char(map[y][x - 1]) || !is_valid_char(map[y + 1][x])
			|| !is_valid_char(map[y - 1][x])))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
